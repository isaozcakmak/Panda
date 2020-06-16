#ifndef PANDA_LEXER
#define PANDA_LEXER

#include <string>
#include <vector>
#include <unordered_map>
#include <Token.h>
#include <Utility/HelperMethods.h>

class Lexer
{
public:
	Lexer(const std::string code);
	~Lexer() {}

	Token getNextToken();

private:
	void advance();
	char peek();
	void skipWhiteSpace();
	void skipComment();
	Token number();
	Token id();
	void error();

private:
	std::string m_code;
	int m_position;
	char m_currentChar;

	std::unordered_map<std::string, Token> m_reservedKeywords;
};

#endif // PANDA_LEXER