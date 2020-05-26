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
	void addChild(AbstractSyntaxTree* child);
	std::vector<AbstractSyntaxTree*> getChildren();

private:
	NodeType m_nodeType;

	std::vector<AbstractSyntaxTree*> m_children;

};


#endif // PANDA_ABSTRACTSYNTAXTREECOMPOUNDNODE