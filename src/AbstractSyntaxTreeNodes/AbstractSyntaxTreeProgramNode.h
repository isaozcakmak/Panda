#ifndef PANDA_ABSTRACTSYNTAXTREEPROGRAMNODE
#define PANDA_ABSTRACTSYNTAXTREEPROGRAMNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeProgramNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeProgramNode(std::string name, AbstractSyntaxTree* block);
	~AbstractSyntaxTreeProgramNode() {}

	virtual NodeType getNodeType();
	AbstractSyntaxTree* getBlock();
	std::string getName();

private:
	NodeType m_nodeType;

	AbstractSyntaxTree* m_block;
	std::string m_name;
};


#endif // PANDA_ABSTRACTSYNTAXTREEPROGRAMNODE