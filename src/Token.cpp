#include "Token.h"

Token::Token(TokenType type, int number) :
	m_type(type),
	m_integer(number),
	m_double(0),
	m_string("")
{
}

Token::Token(TokenType type, double number) :
	m_type(type),
	m_integer(0),
	m_double(number),
	m_string("")
{
}

Token::Token(TokenType type, std::string string) :
	m_type(type),
	m_integer(0),
	m_double(0),
	m_string(string)
{
}

Token::Token(TokenType type) :
	m_type(type),
	m_integer(0),
	m_double(0),
	m_string("")
{
}

Token::Token() :
	m_type(TokenType::Plus),
	m_integer(0),
	m_double(0),
	m_string("")
{
}

Token::TokenType Token::getType() const
{
	return m_type;
}

int Token::getInteger() const
{
	return m_integer;
}

double Token::getDouble() const
{
	return m_double;
}

std::string Token::getString() const
{
	return m_string;
}
