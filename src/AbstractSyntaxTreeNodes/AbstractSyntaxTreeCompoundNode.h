#ifndef PANDA_ABSTRACTSYNTAXTREECOMPOUNDNODE
#define PANDA_ABSTRACTSYNTAXTREECOMPOUNDNODE

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


#endif // PANDA_ABSTRACTSYNTAXTREECOMPOUNDNODE