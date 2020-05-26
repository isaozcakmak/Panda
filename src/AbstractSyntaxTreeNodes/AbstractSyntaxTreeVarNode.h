#ifndef PANDA_ABSTRACTSYNTAXTREEVARNODE
#define PANDA_ABSTRACTSYNTAXTREEVARNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeVarNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeVarNode(Token token);
	~AbstractSyntaxTreeVarNode() {}
	
	virtual NodeType getNodeType();
	int getTokenValue();
	std::string getTokenString();

private:
	NodeType m_nodeType;

	Token m_token;

};


#endif // PANDA_ABSTRACTSYNTAXTREEVARNODE