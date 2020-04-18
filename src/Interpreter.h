#ifndef PANDA_INTERPRETER
#define PANDA_INTERPRETER

#include <string>
#include <vector>
#include <Utility/Command.h>
#include <Lexer.h>
#include <Token.h>

class Interpreter
{
public:
	Interpreter(Lexer lexer);
	~Interpreter() {}

	int expr();

private:
	void eat(Token::TokenType tokenType);
	int factor();
	int term();
	void error();

private:
	Lexer m_lexer;
	Token m_currentToken;
};


#endif // PANDA_INTERPRETER