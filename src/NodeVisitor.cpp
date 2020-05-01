#include <NodeVisitor.h>
#include <iostream>

NodeVisitor::NodeVisitor()
{
}

int NodeVisitor::visit(AbstractSyntaxTree* node)
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
	default:
		break;
	}

	return 0;
}

int NodeVisitor::visitNum(AbstractSyntaxTree* node)
{
	auto nodeType = node->getNodeType();
	if (nodeType == AbstractSyntaxTree::NodeType::Num)
	{
		return reinterpret_cast<AbstractSyntaxTreeNumNode*>(node)->getTokenValue();
	}
	
	throw std::exception("AbstractSyntaxTree* Is Not AbstractSyntaxTreeNumNode*");
	return 0;
}

int NodeVisitor::visitBinOp(AbstractSyntaxTree* node)
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
		case Token::TokenType::Div:
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

int NodeVisitor::visitUnaryOp(AbstractSyntaxTree* node)
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

