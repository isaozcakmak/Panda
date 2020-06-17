#include <Parser.h>
#include <iostream>

Parser::Parser(Lexer lexer) :
	m_lexer(lexer),
	m_currentToken(m_lexer.getNextToken())
{
}

AbstractSyntaxTree* Parser::parse()
{
	return program();
}

AbstractSyntaxTree* Parser::expr()
{
	auto node = term();

	while (m_currentToken.getType() == Token::TokenType::Plus ||
		m_currentToken.getType() == Token::TokenType::Minus)
	{
		auto token = m_currentToken;
		if (token.getType() == Token::TokenType::Plus)
		{
			eat(Token::TokenType::Plus);
			//result += term();
		}
		else if (token.getType() == Token::TokenType::Minus)
		{
			eat(Token::TokenType::Minus);
			//result -= term();
		}

		auto termNode = term();
		node = new AbstractSyntaxTreeBinOpNode(node, token, termNode);

	}

	return node;
}

void Parser::eat(Token::TokenType tokenType)
{
	if (m_currentToken.getType() == tokenType)
		m_currentToken = m_lexer.getNextToken();
	else
		error();
}

AbstractSyntaxTree* Parser::factor()
{
	auto token = m_currentToken;
	auto tokenType = token.getType();

	switch (tokenType)
	{
	case Token::TokenType::Plus:
		{
			eat(Token::TokenType::Plus);
			return new AbstractSyntaxTreeUnaryOpNode(token, factor());
			break;
		}
	case Token::TokenType::Minus:
		{
			eat(Token::TokenType::Minus);
			return new AbstractSyntaxTreeUnaryOpNode(token, factor());
			break;
		}
	case Token::TokenType::Integer:
		{
			eat(Token::TokenType::Integer);
			//return token.getValue();
			return new AbstractSyntaxTreeNumNode(token);
			break;
		}
	case Token::TokenType::LeftParenthesis:
		{
			eat(Token::TokenType::LeftParenthesis);
			auto node = expr();
			eat(Token::TokenType::RightParenthesis);
			return node;
			break;
		}

	default:
		{
			auto node = variable();
			return node;
			break;
		}
	}

	error();
	return new AbstractSyntaxTreeNumNode(token);
}

AbstractSyntaxTree* Parser::term()
{
	auto node = factor();

	while (m_currentToken.getType() == Token::TokenType::Mul || 
			m_currentToken.getType() == Token::TokenType::Div)
	{
		auto token = m_currentToken;
		auto tokenType = token.getType();

		switch (tokenType)
		{
		case Token::TokenType::Mul:
			eat(Token::TokenType::Mul);
			//result *= factor();
			break;
		case Token::TokenType::Div:
			eat(Token::TokenType::Div);
			//result /= factor();
			break;
		default:
			break;
		}

		auto factorNode = factor();
		node = new AbstractSyntaxTreeBinOpNode(node, token, factorNode);
		
	}

	return node;
}

AbstractSyntaxTree* Parser::program()
{
	eat(Token::TokenType::Program);

	auto varNode = variable();
	std::string programName = reinterpret_cast<AbstractSyntaxTreeVarNode*>(varNode)->getTokenString();

	eat(Token::TokenType::Semi);

	auto blockNode = block();
	auto programNode = new AbstractSyntaxTreeProgramNode(programName, blockNode);
	
	eat(Token::TokenType::Dot);

	return programNode;
}

AbstractSyntaxTree* Parser::block()
{
	auto declarationNodes = declarations();
	auto compoundStatementNode = compoundStatement();

	return new AbstractSyntaxTreeBlockNode(declarationNodes, compoundStatementNode);
}

std::vector<AbstractSyntaxTree*> Parser::declarations()
{
	std::vector<AbstractSyntaxTree*> declarations;

	if (m_currentToken.getType() == Token::TokenType::Var)
	{
		eat(Token::TokenType::Var);

		while (m_currentToken.getType() == Token::TokenType::ID)
		{
			auto varDeclarations = variableDeclaration();
			declarations.insert(declarations.begin(), varDeclarations.begin(), varDeclarations.end());
			eat(Token::TokenType::Semi);
		}
	}

	return declarations;
}

std::vector<AbstractSyntaxTree*> Parser::variableDeclaration()
{
	std::vector<AbstractSyntaxTree*> results;

	std::vector<AbstractSyntaxTreeVarNode*> varNodes;
	varNodes.push_back(new AbstractSyntaxTreeVarNode(m_currentToken));

	eat(Token::TokenType::ID);

	while (m_currentToken.getType() == Token::TokenType::Comma)
	{
		eat(Token::TokenType::Comma);
		varNodes.push_back(new AbstractSyntaxTreeVarNode(m_currentToken));
		eat(Token::TokenType::ID);
	}

	eat(Token::TokenType::Colon);

	auto typeNode = typeSpec();

	for (auto item : varNodes)
	{
		results.push_back(new AbstractSyntaxTreeVarDeclarationNode(item, typeNode));
	}

	return results;
}

AbstractSyntaxTreeTypeNode* Parser::typeSpec()
{
	auto token = m_currentToken;

	if (m_currentToken.getType() == Token::TokenType::Integer)
		eat(Token::TokenType::Integer);
	else
		eat(Token::TokenType::Real);

	return new AbstractSyntaxTreeTypeNode(token);
}

AbstractSyntaxTree* Parser::compoundStatement()
{
	eat(Token::TokenType::Begin);

	auto nodes = statementList();

	eat(Token::TokenType::End);

	auto root = new AbstractSyntaxTreeCompoundNode();

	for (size_t i = 0; i < nodes.size(); i++)
	{
		root->addChild(nodes[i]);
	}

	return root;
}

std::vector<AbstractSyntaxTree*> Parser::statementList()
{
	std::vector< AbstractSyntaxTree*> results;

	auto node = statement();

	results.push_back(node);

	while (m_currentToken.getType() == Token::TokenType::Semi)
	{
		eat(Token::TokenType::Semi);
		results.push_back(statement());
	}

	if (m_currentToken.getType() == Token::TokenType::ID)
		error();

	return results;
}

AbstractSyntaxTree* Parser::statement()
{
	AbstractSyntaxTree* node = nullptr;

	if (m_currentToken.getType() == Token::TokenType::Begin)
		node = compoundStatement();
	else if (m_currentToken.getType() == Token::TokenType::ID)
		node = assignmentStatement();
	else
		node = empty();

	return node;
}

AbstractSyntaxTree* Parser::assignmentStatement()
{
	auto left = variable();
	auto token = m_currentToken;

	eat(Token::TokenType::Assign);

	auto right = expr();

	return new AbstractSyntaxTreeAssignNode(left, token, right);
}

AbstractSyntaxTree* Parser::variable()
{
	auto node = new AbstractSyntaxTreeVarNode(m_currentToken);
	eat(Token::TokenType::ID);

	return node;
}

AbstractSyntaxTree* Parser::empty()
{
	return new AbstractSyntaxTreeNoOpNode();
}

void Parser::error()
{
	throw std::exception("Invalid syntax");
}



