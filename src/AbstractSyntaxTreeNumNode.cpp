#include <AbstractSyntaxTreeNumNode.h>
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

int AbstractSyntaxTreeNumNode::getTokenValue()
{
	return m_token.getValue();
}

