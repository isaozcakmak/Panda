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
		BinOp,
		UnaryOp,
		Compound
	};

	AbstractSyntaxTree();
//	AbstractSyntaxTree(Token token);
//	AbstractSyntaxTree(AbstractSyntaxTree* left, Token op, AbstractSyntaxTree* right);
//	AbstractSyntaxTree(Token op, AbstractSyntaxTree* expr);
	~AbstractSyntaxTree() {}
//
//	AbstractSyntaxTree& operator=(const AbstractSyntaxTree &other);
//
	virtual NodeType getNodeType() = 0;
//	int getTokenValue();
//	Token::TokenType getOpTokenType();
//	AbstractSyntaxTree* getLeft();
//	AbstractSyntaxTree* getRight();
//	AbstractSyntaxTree* getExpr();
//
//private:
//	NodeType m_nodeType;
//
//	Token m_token;
//
//	AbstractSyntaxTree* m_left;
//	AbstractSyntaxTree* m_right;
//	Token m_op;
//
//	AbstractSyntaxTree* m_expr;

};


#endif // PANDA_ABSTRACTSYNTAXTREE