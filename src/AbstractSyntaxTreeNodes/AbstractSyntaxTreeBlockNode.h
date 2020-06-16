#ifndef PANDA_ABSTRACTSYNTAXTREEBLOCKNODE
#define PANDA_ABSTRACTSYNTAXTREEBLOCKNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeBlockNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeBlockNode(std::vector<AbstractSyntaxTree*> declarations, AbstractSyntaxTree* compoundStatement);
	~AbstractSyntaxTreeBlockNode() {}

	virtual NodeType getNodeType();
	std::vector<AbstractSyntaxTree*> getDeclarations();
	AbstractSyntaxTree* getCompoundStatement();

private:
	NodeType m_nodeType;

	std::vector<AbstractSyntaxTree*> m_declarations;
	AbstractSyntaxTree* m_compoundStatement;
};


#endif // PANDA_ABSTRACTSYNTAXTREEBLOCKNODE