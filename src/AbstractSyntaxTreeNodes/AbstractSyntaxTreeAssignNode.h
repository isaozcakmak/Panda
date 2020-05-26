#ifndef PANDA_ABSTRACTSYNTAXTREEASSIGNNODE
#define PANDA_ABSTRACTSYNTAXTREEASSIGNNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeAssignNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeAssignNode(AbstractSyntaxTree* left, Token op, AbstractSyntaxTree* right);
	~AbstractSyntaxTreeAssignNode() {}

	virtual NodeType getNodeType();
	Token::TokenType getOpTokenType();
	AbstractSyntaxTree* getLeft();
	AbstractSyntaxTree* getRight();
	std::string getTokenString();

private:
	NodeType m_nodeType;

	AbstractSyntaxTree* m_left;
	AbstractSyntaxTree* m_right;
	Token m_op;
};


#endif // PANDA_ABSTRACTSYNTAXTREEASSIGNNODE