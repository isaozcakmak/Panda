#include <Parser.h>
#include <iostream>

Parser::Parser(Lexer lexer) :
	m_lexer(lexer),
	m_currentToken(m_lexer.getNextToken())
{
}

AbstractSyntaxTree* Parser::parse()
{
	return expr();
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
		node = new AbstractSyntaxTree(node, token, termNode);

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
			return new AbstractSyntaxTree(token, factor());
			break;
		}
	case Token::TokenType::Minus:
		{
			eat(Token::TokenType::Minus);
			return new AbstractSyntaxTree(token, factor());
			break;
		}
	case Token::TokenType::Integer:
		{
			eat(Token::TokenType::Integer);
			//return token.getValue();
			return new AbstractSyntaxTree(token);
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
		break;
	}

	error();
	return new AbstractSyntaxTree(token);
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
		node = new AbstractSyntaxTree(node, token, factorNode);
		
	}

	return node;
}

void Parser::error()
{
	throw std::exception("Invalid syntax");
}



