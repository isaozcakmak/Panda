#ifndef PANDA_ABSTRACTSYNTAXTREEBINOPNODE
#define PANDA_ABSTRACTSYNTAXTREEBINOPNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeBinOpNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeBinOpNode(AbstractSyntaxTree* left, Token op, AbstractSyntaxTree* right);
	~AbstractSyntaxTreeBinOpNode() {}

	virtual NodeType getNodeType();
	Token::TokenType getOpTokenType();
	AbstractSyntaxTree* getLeft();
	AbstractSyntaxTree* getRight();

private:
	NodeType m_nodeType;

	AbstractSyntaxTree* m_left;
	AbstractSyntaxTree* m_right;
	Token m_op;
};


#endif // PANDA_ABSTRACTSYNTAXTREEBINOPNODE