#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeAssignNode.h>
#include <iostream>

AbstractSyntaxTreeAssignNode::AbstractSyntaxTreeAssignNode(AbstractSyntaxTree* left, Token op, AbstractSyntaxTree* right) :
	m_nodeType(NodeType::BinOp),
	m_left(left),
	m_op(op),
	m_right(right)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeAssignNode::getNodeType()
{
	return m_nodeType;
}

Token::TokenType AbstractSyntaxTreeAssignNode::getOpTokenType()
{
	return m_op.getType();
}

AbstractSyntaxTree* AbstractSyntaxTreeAssignNode::getLeft()
{
	return m_left;
}

AbstractSyntaxTree* AbstractSyntaxTreeAssignNode::getRight()
{
	return m_right;
}


