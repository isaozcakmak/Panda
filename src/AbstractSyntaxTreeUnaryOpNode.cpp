#include <AbstractSyntaxTreeUnaryOpNode.h>
#include <iostream>

AbstractSyntaxTreeUnaryOpNode::AbstractSyntaxTreeUnaryOpNode(Token op, AbstractSyntaxTree* expr) :
	m_nodeType(NodeType::UnaryOp),
	m_op(op),
	m_expr(expr)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeUnaryOpNode::getNodeType()
{
	return m_nodeType;
}

Token::TokenType AbstractSyntaxTreeUnaryOpNode::getOpTokenType()
{
	return m_op.getType();
}

AbstractSyntaxTree* AbstractSyntaxTreeUnaryOpNode::getExpr()
{
	return m_expr;
}

