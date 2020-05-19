#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeBinOpNode.h>
#include <iostream>

AbstractSyntaxTreeBinOpNode::AbstractSyntaxTreeBinOpNode(AbstractSyntaxTree* left, Token op, AbstractSyntaxTree* right) :
	m_nodeType(NodeType::BinOp),
	m_left(left),
	m_op(op),
	m_right(right)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeBinOpNode::getNodeType()
{
	return m_nodeType;
}

Token::TokenType AbstractSyntaxTreeBinOpNode::getOpTokenType()
{
	return m_op.getType();
}

AbstractSyntaxTree* AbstractSyntaxTreeBinOpNode::getLeft()
{
	return m_left;
}

AbstractSyntaxTree* AbstractSyntaxTreeBinOpNode::getRight()
{
	return m_right;
}


