#include "Token.h"

Token::Token(TokenType type, int number) :
	m_type(type),
	m_number(number),
	m_string("")
{
}

Token::Token(TokenType type, std::string string) :
	m_type(type),
	m_number(0),
	m_string(string)
{
}

Token::Token(TokenType type) :
	m_type(type),
	m_number(0),
	m_string("")
{
}

Token::Token() :
	m_type(TokenType::Plus),
	m_number(0),
	m_string("")
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

std::string Token::getString() const
{
	return m_string;
}
