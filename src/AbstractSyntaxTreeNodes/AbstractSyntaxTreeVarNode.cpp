#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarNode.h>
#include <iostream>

AbstractSyntaxTreeVarNode::AbstractSyntaxTreeVarNode(Token token) :
	m_nodeType(NodeType::Var),
	m_token(token)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeVarNode::getNodeType()
{
	return m_nodeType;
}

double AbstractSyntaxTreeVarNode::getTokenValue()
{
	return m_token.getType() == Token::TokenType::Integer ? m_token.getInteger() : m_token.getDouble();
}

std::string AbstractSyntaxTreeVarNode::getTokenString()
{
	return m_token.getString();
}

