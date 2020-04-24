#ifndef PANDA_INTERPRETER
#define PANDA_INTERPRETER

#include <string>
#include <vector>
#include <Utility/Command.h>
#include <Lexer.h>
#include <Token.h>
#include <Parser.h>

class Interpreter
{
public:
	Interpreter(Parser parser);
	~Interpreter() {}

	int interpret();

private:
	Parser m_parser;
};


#endif // PANDA_INTERPRETER