#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeNumNode.h>
#include <iostream>

AbstractSyntaxTreeNumNode::AbstractSyntaxTreeNumNode(Token token) :
	m_nodeType(NodeType::Num),
	m_token(token)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeNumNode::getNodeType()
{
	return m_nodeType;
}

double AbstractSyntaxTreeNumNode::getTokenValue()
{
	return m_token.getType() == Token::TokenType::Integer ? m_token.getInteger() : m_token.getDouble();
}

