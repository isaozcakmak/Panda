#ifndef PANDA_LEXER
#define PANDA_LEXER

#include <string>
#include <vector>

class Lexer
{
	Lexer(const std::vector<std::string> code);
	~Lexer() {}

private:
	std::vector<std::string> m_code;

};

#endif // PANDA_LEXER