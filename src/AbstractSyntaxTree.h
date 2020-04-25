#ifndef PANDA_ABSTRACTSYNTAXTREE
#define PANDA_ABSTRACTSYNTAXTREE

#include <string>
#include <vector>
#include <Token.h>

class AbstractSyntaxTree
{
public:
	enum class NodeType
	{
		Num = 0x01,
		BinOp
	};

	AbstractSyntaxTree(Token token);
	AbstractSyntaxTree(AbstractSyntaxTree& left, Token op, AbstractSyntaxTree& right);
	~AbstractSyntaxTree() {}

	AbstractSyntaxTree& operator=(const AbstractSyntaxTree &other);

	NodeType getNodeType();
	int getTokenValue();
	Token::TokenType getOpTokenType();
	AbstractSyntaxTree getLeft();
	AbstractSyntaxTree getRight();


private:
	NodeType m_nodeType;

	Token m_token;

	AbstractSyntaxTree* m_left;
	AbstractSyntaxTree* m_right;
	Token m_op;

};


#endif // PANDA_ABSTRACTSYNTAXTREE