#ifndef PANDA_TOKEN
#define PANDA_TOKEN

#include <string>

class Token
{
public:
	enum class TokenType
	{
		Plus = 0x01,
		Minus,
		Mul,
		Div,
		Integer,
		LeftParenthesis,
		RightParenthesis,
		ID,
		Assign,
		Begin,
		End,
		Semi,
		Dot,
		TokenEOF
	};

	Token(TokenType type, int number);
	Token(TokenType type, std::string string);
	Token(TokenType type);
	Token();
	~Token() {}

	TokenType getType() const;
	int getValue() const;
	std::string getString() const;

private:
	TokenType m_type;
	int m_number;
	std::string m_string;
};

#endif // PANDA_TOKEN