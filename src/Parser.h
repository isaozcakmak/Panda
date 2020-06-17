#ifndef PANDA_PARSER
#define PANDA_PARSER

#include <string>
#include <vector>
#include <Lexer.h>
#include <Token.h>
#include <AbstractSyntaxTree.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeNumNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeBinOpNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeUnaryOpNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeAssignNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeCompoundNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeNoOpNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeProgramNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeBlockNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarDeclarationNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeTypeNode.h>

class Parser
{
public:
	Parser(Lexer lexer);
	~Parser() {}

	AbstractSyntaxTree* parse();

private:
	AbstractSyntaxTree* expr();
	void eat(Token::TokenType tokenType);
	AbstractSyntaxTree* factor();
	AbstractSyntaxTree* term();
	AbstractSyntaxTree* program();
	std::vector<AbstractSyntaxTreeVarDeclarationNode*> declarations();
	std::vector<AbstractSyntaxTreeVarDeclarationNode*> variableDeclaration();
	AbstractSyntaxTreeTypeNode* typeSpec();
	AbstractSyntaxTree* compoundStatement();
	std::vector< AbstractSyntaxTree*> statementList();
	AbstractSyntaxTree* statement();
	AbstractSyntaxTree* assignmentStatement();
	AbstractSyntaxTree* variable();
	AbstractSyntaxTree* empty();

	void error();

private:
	Lexer m_lexer;
	Token m_currentToken;
};


#endif // PANDA_PARSER