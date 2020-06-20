#include <Interpreter.h>
#include <iostream>

Interpreter::Interpreter(Parser parser) :
	m_parser(parser)
{
}

double Interpreter::interpret()
{
	NodeVisitor nodeVisitor;
	auto abstractSyntaxTree = m_parser.parse();
	auto result = nodeVisitor.visit(abstractSyntaxTree);
	nodeVisitor.printVariables();

	return result;
}

