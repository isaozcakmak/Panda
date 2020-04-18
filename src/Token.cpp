#include "Token.h"

Token::Token(TokenType type, int number) :
	m_type(type),
	m_number(number)
{
}

Token::Token(TokenType type) :
	m_type(type),
	m_number(0)
{
}

Token::TokenType Token::getType() const
{
	return m_type;
}

int Token::getValue() const
{
	return m_number;
}
