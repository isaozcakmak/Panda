#ifndef PANDA_ABSTRACTSYNTAXTREENUMNODE
#define PANDA_ABSTRACTSYNTAXTREENUMNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeCompoundNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeCompoundNode();
	~AbstractSyntaxTreeCompoundNode() {}
	
	virtual NodeType getNodeType();

private:
	NodeType m_nodeType;

};


#endif // PANDA_ABSTRACTSYNTAXTREENUMNODE