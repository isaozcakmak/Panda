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
	default:
		break;
	}

	return 0;
}

int NodeVisitor::visitNum(AbstractSyntaxTree* node)
{
	return node->getTokenValue();
}

int NodeVisitor::visitBinOp(AbstractSyntaxTree* node)
{
	auto opTokenType = node->getOpTokenType();

	switch (opTokenType)
	{
	case Token::TokenType::Plus:
		return visit(node->getLeft()) + visit(node->getRight());
		break;
	case Token::TokenType::Minus:
		return visit(node->getLeft()) - visit(node->getRight());
		break;
	case Token::TokenType::Mul:
		return visit(node->getLeft()) * visit(node->getRight());
		break;
	case Token::TokenType::Div:
		return visit(node->getLeft()) / visit(node->getRight());
		break;
	default:
		break;
	}

	return 0;
}

