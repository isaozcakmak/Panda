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

void AbstractSyntaxTreeCompoundNode::addChild(AbstractSyntaxTree* child)
{
	m_children.push_back(child);
}

std::vector<AbstractSyntaxTree*> AbstractSyntaxTreeCompoundNode::getChildren()
{
	return m_children;
}

