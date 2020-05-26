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

int AbstractSyntaxTreeVarNode::getTokenValue()
{
	return m_token.getValue();
}

std::string AbstractSyntaxTreeVarNode::getTokenString()
{
	return m_token.getString();
}

