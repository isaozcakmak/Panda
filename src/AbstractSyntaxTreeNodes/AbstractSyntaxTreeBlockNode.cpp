#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeBlockNode.h>
#include <iostream>

AbstractSyntaxTreeBlockNode::AbstractSyntaxTreeBlockNode(std::vector<AbstractSyntaxTree*> declarations, AbstractSyntaxTree* compoundStatement) :
	m_nodeType(NodeType::Block),
	m_declarations(declarations),
	m_compoundStatement(compoundStatement)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeBlockNode::getNodeType()
{
	return m_nodeType;
}

std::vector<AbstractSyntaxTree*> AbstractSyntaxTreeBlockNode::getDeclarations()
{
	return m_declarations;
}

AbstractSyntaxTree* AbstractSyntaxTreeBlockNode::getCompoundStatement()
{
	return m_compoundStatement;
}


