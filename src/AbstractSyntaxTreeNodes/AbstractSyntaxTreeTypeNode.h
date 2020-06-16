#ifndef PANDA_ABSTRACTSYNTAXTREETYPENODE
#define PANDA_ABSTRACTSYNTAXTREETYPENODE

#include <string>
#include <vector>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class AbstractSyntaxTreeTypeNode : public AbstractSyntaxTree
{
public:
	AbstractSyntaxTreeTypeNode(Token token);
	~AbstractSyntaxTreeTypeNode() {}
	
	virtual NodeType getNodeType();
	Token::TokenType getTokenType();

private:
	NodeType m_nodeType;

	Token m_token;
};


#endif // PANDA_ABSTRACTSYNTAXTREETYPENODE