#ifndef PANDA_LEXER
#define PANDA_LEXER

#include <string>
#include <vector>
#include <Token.h>

class Lexer
{
public:
	Lexer(const std::vector<std::string> code);
	~Lexer() {}

	Token getNextToken();

private:
	void advance();
	void skipWhiteSpace();
	int integer();
	void error();

private:
	std::vector<std::string> m_code;
	int m_index;
	int m_position;
	char m_currentChar;
};

#endif // PANDA_LEXER