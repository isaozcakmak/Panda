#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarDeclarationNode.h>
#include <iostream>

AbstractSyntaxTreeVarDeclarationNode::AbstractSyntaxTreeVarDeclarationNode(AbstractSyntaxTreeVarNode* varNode, AbstractSyntaxTreeTypeNode* typeNode) :
	m_nodeType(NodeType::VarDecl),
	m_varNode(varNode),
	m_typeNode(typeNode)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeVarDeclarationNode::getNodeType()
{
	return m_nodeType;
}

AbstractSyntaxTreeVarNode* AbstractSyntaxTreeVarDeclarationNode::getVarNode()
{
	return m_varNode;
}

AbstractSyntaxTreeTypeNode* AbstractSyntaxTreeVarDeclarationNode::getTypeNode()
{
	return m_typeNode;
}


