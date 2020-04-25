#ifndef PANDA_PARSER
#define PANDA_PARSER

#include <string>
#include <vector>
#include <Utility/Command.h>
#include <Lexer.h>
#include <Token.h>
#include <AbstractSyntaxTree.h>

class Parser
{
public:
	Parser(Lexer lexer);
	~Parser() {}

	AbstractSyntaxTree parse();

private:
	AbstractSyntaxTree expr();
	void eat(Token::TokenType tokenType);
	AbstractSyntaxTree factor();
	AbstractSyntaxTree term();
	void error();

private:
	Lexer m_lexer;
	Token m_currentToken;
};


#endif // PANDA_PARSER