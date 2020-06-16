#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeProgramNode.h>
#include <iostream>

AbstractSyntaxTreeProgramNode::AbstractSyntaxTreeProgramNode(std::string name, AbstractSyntaxTree* block) :
	m_nodeType(NodeType::Program),
	m_block(block),
	m_name(name)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeProgramNode::getNodeType()
{
	return m_nodeType;
}

AbstractSyntaxTree* AbstractSyntaxTreeProgramNode::getBlock()
{
	return m_block;
}

std::string AbstractSyntaxTreeProgramNode::getName()
{
	return m_name;
}

