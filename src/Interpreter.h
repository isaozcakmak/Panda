#ifndef PANDA_INTERPRETER
#define PANDA_INTERPRETER

#include <string>
#include <vector>
#include <Parser.h>
#include <NodeVisitor.h>

class Interpreter
{
public:
	Interpreter(Parser parser);
	~Interpreter() {}

	double interpret();

private:
	Parser m_parser;
};


#endif // PANDA_INTERPRETER