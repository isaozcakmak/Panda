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
		Integer,
		Real,
		IntegerConst,
		RealConst,
		IntegerDiv,
		FloatDiv,
		LeftParenthesis,
		RightParenthesis,
		ID,
		Assign,
		Begin,
		End,
		Semi,
		Dot,
		Program,
		Var,
		Colon,
		Comma,
		TokenEOF
	};

	Token(TokenType type, int number);
	Token(TokenType type, double number);
	Token(TokenType type, std::string string);
	Token(TokenType type);
	Token();
	~Token() {}

	TokenType getType() const;
	int getInteger() const;
	double getDouble() const;
	std::string getString() const;

private:
	TokenType m_type;
	int m_integer;
	double m_double;
	std::string m_string;
};

#endif // PANDA_TOKEN