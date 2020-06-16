#ifndef PANDA_ABSTRACTSYNTAXTREEVARDECLARATIONNODE
#define PANDA_ABSTRACTSYNTAXTREEVARDECLARATIONNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeTypeNode.h>

class AbstractSyntaxTreeVarDeclarationNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeVarDeclarationNode(AbstractSyntaxTreeVarNode* varNode, AbstractSyntaxTreeTypeNode* typeNode);
	~AbstractSyntaxTreeVarDeclarationNode() {}
	
	virtual NodeType getNodeType();
	AbstractSyntaxTreeVarNode* getVarNode();
	AbstractSyntaxTreeTypeNode* getTypeNode();

private:
	NodeType m_nodeType;

	AbstractSyntaxTreeVarNode* m_varNode;
	AbstractSyntaxTreeTypeNode* m_typeNode;
};


#endif // PANDA_ABSTRACTSYNTAXTREEVARDECLARATIONNODE