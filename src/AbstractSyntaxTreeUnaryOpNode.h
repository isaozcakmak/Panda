#ifndef PANDA_ABSTRACTSYNTAXTREEUNARYOPNODE
#define PANDA_ABSTRACTSYNTAXTREEUNARYOPNODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>


class AbstractSyntaxTreeUnaryOpNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeUnaryOpNode(Token op, AbstractSyntaxTree* expr);
	~AbstractSyntaxTreeUnaryOpNode() {}
	
	NodeType getNodeType();
	Token::TokenType getOpTokenType();
	AbstractSyntaxTree* getExpr();

private:
	NodeType m_nodeType;
	
	Token m_op;
	AbstractSyntaxTree* m_expr;

};


#endif // PANDA_ABSTRACTSYNTAXTREEUNARYOPNODE