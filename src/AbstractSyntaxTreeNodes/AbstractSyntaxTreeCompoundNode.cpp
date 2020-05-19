#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeCompoundNode.h>
#include <iostream>

AbstractSyntaxTreeCompoundNode::AbstractSyntaxTreeCompoundNode() :
	m_nodeType(NodeType::Compound)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeCompoundNode::getNodeType()
{
	return m_nodeType;
}

