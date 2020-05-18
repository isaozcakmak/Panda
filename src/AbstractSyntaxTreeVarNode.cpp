#include <AbstractSyntaxTreeVarNode.h>
#include <iostream>

AbstractSyntaxTreeVarNode::AbstractSyntaxTreeVarNode(Token token) :
	m_nodeType(NodeType::Num),
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

