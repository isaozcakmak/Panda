#ifndef PANDA_TOKEN
#define PANDA_TOKEN

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
		TokenEOF
	};

	Token(TokenType type, int number);
	Token(TokenType type);
	~Token() {}

	TokenType getType() const;
	int getValue() const;

private:
	TokenType m_type;
	int m_number;
};

#endif // PANDA_TOKEN