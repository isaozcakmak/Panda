#include <NodeVisitor.h>
#include <iostream>

NodeVisitor::NodeVisitor()
{
}

double NodeVisitor::visit(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();

	switch (nodeType)
	{
	case AbstractSyntaxTree::NodeType::Num:
		return visitNum(node);
		break;
	case AbstractSyntaxTree::NodeType::BinOp:
		return visitBinOp(node);
		break;
	case AbstractSyntaxTree::NodeType::UnaryOp:
		return visitUnaryOp(node);
		break;
	case AbstractSyntaxTree::NodeType::Compound:
		visitCompound(node);
		break;
	case AbstractSyntaxTree::NodeType::Assign:
		visitAssign(node);
		break;
	case AbstractSyntaxTree::NodeType::Var:
		return visitVar(node);
		break;
	case AbstractSyntaxTree::NodeType::NoOp:
		visitNoOp(node);
		break;
	case AbstractSyntaxTree::NodeType::Program:
		visitProgram(node);
		break;
	case AbstractSyntaxTree::NodeType::Block:
		visitBlock(node);
		break;
	case AbstractSyntaxTree::NodeType::VarDecl:
		visitVarDecleration(node);
		break;
	case AbstractSyntaxTree::NodeType::Type:
		visitType(node);
		break;
	default:
		break;
	}

	return 0;
}

std::unordered_map<std::string, double> NodeVisitor::getVariables()
{
	return m_variables;
}

void NodeVisitor::printVariables()
{
	for (auto variable : m_variables)
	{
		std::cout << "Variable Name: " << variable.first <<
			"\tVariable Value: " << variable.second << std::endl;
	}
}

double NodeVisitor::visitNum(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::Num)
	{
		return reinterpret_cast<AbstractSyntaxTreeNumNode*>(node)->getTokenValue();
	}
	
	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeNumNode*");
	return 0;
}

double NodeVisitor::visitBinOp(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::BinOp)
	{
		auto binOpNode = reinterpret_cast<AbstractSyntaxTreeBinOpNode*>(node);

		auto opTokenType = binOpNode->getOpTokenType();

		switch (opTokenType)
		{
		case Token::TokenType::Plus:
			return visit(binOpNode->getLeft()) + visit(binOpNode->getRight());
			break;
		case Token::TokenType::Minus:
			return visit(binOpNode->getLeft()) - visit(binOpNode->getRight());
			break;
		case Token::TokenType::Mul:
			return visit(binOpNode->getLeft()) * visit(binOpNode->getRight());
			break;
		case Token::TokenType::IntegerDiv:
			return static_cast<int>(visit(binOpNode->getLeft()) / visit(binOpNode->getRight()));
			break;
		case Token::TokenType::FloatDiv:
			return visit(binOpNode->getLeft()) / visit(binOpNode->getRight());
			break;
		default:
			break;
		}

		return 0;

	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeBinOpNode*");
	return 0;
}

double NodeVisitor::visitUnaryOp(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::UnaryOp)
	{
		auto unaryOpNode = reinterpret_cast<AbstractSyntaxTreeUnaryOpNode*>(node);

		auto opTokenType = unaryOpNode->getOpTokenType();

		switch (opTokenType)
		{
		case Token::TokenType::Plus:
			return +visit(unaryOpNode->getExpr());
			break;
		case Token::TokenType::Minus:
			return -visit(unaryOpNode->getExpr());
			break;
		default:
			break;
		}

		return 0;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeUnaryOpNode*");
	return 0;
}

void NodeVisitor::visitCompound(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::Compound)
	{
		auto compoundNode = reinterpret_cast<AbstractSyntaxTreeCompoundNode*>(node);

		auto children = compoundNode->getChildren();

		for (size_t i = 0; i < children.size(); i++)
		{
			visit(children[i]);
		}

		return;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeCompoundNode*");
	return;
}

void NodeVisitor::visitAssign(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::Assign)
	{
		auto assignNode = reinterpret_cast<AbstractSyntaxTreeAssignNode*>(node);
		auto leftNode = reinterpret_cast<AbstractSyntaxTreeVarNode*>(assignNode->getLeft());

		auto variableName = leftNode->getTokenString();

		Utility::HelperMethods::Instance().toLower(variableName);

		m_variables[variableName] = visit(assignNode->getRight());
		return;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeAssignNode*");
	return;
}

double NodeVisitor::visitVar(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::Var)
	{
		auto varNode = reinterpret_cast<AbstractSyntaxTreeVarNode*>(node);
		auto variableName = varNode->getTokenString();

		Utility::HelperMethods::Instance().toLower(variableName);

		if (m_variables.contains(variableName))
		{
			return m_variables[variableName];
		}
		else
		{
			std::string errorMessage = variableName + " Variable Does Not Exist";
			throw std::exception(errorMessage.c_str());
			return 0;
		}
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeVarNode*");
	return 0;
}

void NodeVisitor::visitNoOp(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::NoOp)
	{
		return;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeNoOpNode*");
	return;
}

void NodeVisitor::visitProgram(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::Program)
	{
		auto programNode = reinterpret_cast<AbstractSyntaxTreeProgramNode*>(node);

		visit(programNode->getBlock());
		return;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeProgramNode*");
	return;
}

void NodeVisitor::visitBlock(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::Block)
	{
		auto blockNode = reinterpret_cast<AbstractSyntaxTreeBlockNode*>(node);

		for (auto item : blockNode->getDeclarations())
		{
			visit(item);
		}

		visit(blockNode->getCompoundStatement());
		return;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeBlockNode*");
	return;
}

void NodeVisitor::visitVarDecleration(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::VarDecl)
	{
		return;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeVarDeclarationNode*");
	return;
}

void NodeVisitor::visitType(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::VarDecl)
	{
		return;
	}

	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeTypeNode*");
	return;
}

