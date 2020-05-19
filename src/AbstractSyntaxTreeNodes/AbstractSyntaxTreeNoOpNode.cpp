#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeNoOpNode.h>
#include <iostream>

AbstractSyntaxTreeNoOpNode::AbstractSyntaxTreeNoOpNode() :
	m_nodeType(NodeType::Compound)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeNoOpNode::getNodeType()
{
	return m_nodeType;
}

