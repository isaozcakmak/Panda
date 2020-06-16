#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeTypeNode.h>
#include <iostream>

AbstractSyntaxTreeTypeNode::AbstractSyntaxTreeTypeNode(Token token) :
	m_nodeType(NodeType::Type),
	m_token(token)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeTypeNode::getNodeType()
{
	return m_nodeType;
}

Token::TokenType AbstractSyntaxTreeTypeNode::getTokenType()
{
	return m_token.getType();
}


