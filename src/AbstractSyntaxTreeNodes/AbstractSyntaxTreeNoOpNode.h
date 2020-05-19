#ifndef PANDA_ABSTRACTSYNTAXTREENOOPNODE
#define PANDA_ABSTRACTSYNTAXTREENOOPNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeNoOpNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeNoOpNode();
	~AbstractSyntaxTreeNoOpNode() {}
	
	virtual NodeType getNodeType();

private:
	NodeType m_nodeType;

};


#endif // PANDA_ABSTRACTSYNTAXTREENOOPNODE