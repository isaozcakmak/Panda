#ifndef PANDA_PARSER
#define PANDA_PARSER

#include <string>
#include <vector>
#include <Utility/Command.h>
#include <Lexer.h>
#include <Token.h>

class Parser
{
public:
	Parser(Lexer lexer);
	~Parser() {}

private:
	int expr();
	void eat(Token::TokenType tokenType);
	int factor();
	int term();
	void error();

private:
	Lexer m_lexer;
	Token m_currentToken;
};


#endif // PANDA_PARSER