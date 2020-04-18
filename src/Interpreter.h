#ifndef PANDA_INTERPRETER
#define PANDA_INTERPRETER

#include <string>
#include <vector>
#include <Utility/Command.h>
#include <Lexer.h>

class Interpreter
{
public:
	Interpreter(const std::vector<std::string> code);
	~Interpreter() {}

	void run();

private:
	//Utility::Command getCommand();
	//std::string getPrintString();

	int getNumber(std::string value, int& index);
	Utility::Command getOperator(std::string value, int& index);
	void skipWhitespace(int& index);

	int getDigit(char value);
	Utility::Command getOperator(char value);
	bool isOperator(char value);

private:
	std::vector<std::string> m_code;
};


#endif // PANDA_INTERPRETER