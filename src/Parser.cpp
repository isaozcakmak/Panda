#include <Parser.h>
#include <iostream>

Parser::Parser(Lexer lexer) :
	m_lexer(lexer),
	m_currentToken(m_lexer.getNextToken())
{
}

int Parser::expr()
{
	auto result = term();

	while (m_currentToken.getType() == Token::TokenType::Plus ||
		m_currentToken.getType() == Token::TokenType::Minus)
	{
		auto token = m_currentToken;
		if (token.getType() == Token::TokenType::Plus)
		{
			eat(Token::TokenType::Plus);
			result += term();
		}
		else if (token.getType() == Token::TokenType::Minus)
		{
			eat(Token::TokenType::Minus);
			result -= term();
		}
	}

	return result;
}

void Parser::eat(Token::TokenType tokenType)
{
	if (m_currentToken.getType() == tokenType)
		m_currentToken = m_lexer.getNextToken();
	else
		error();
}

int Parser::factor()
{
	auto token = m_currentToken;

	if (token.getType() == Token::TokenType::Integer)
	{
		eat(Token::TokenType::Integer);
		return token.getValue();
	}
	else if (token.getType() == Token::TokenType::LeftParenthesis)
	{
		eat(Token::TokenType::LeftParenthesis);
		auto result = expr();
		eat(Token::TokenType::RightParenthesis);
		return result;
	}

	error();
	return 0;
}

int Parser::term()
{
	auto result = factor();

	while (m_currentToken.getType() == Token::TokenType::Mul || 
			m_currentToken.getType() == Token::TokenType::Div)
	{
		auto token = m_currentToken;
		if (token.getType() == Token::TokenType::Mul)
		{
			eat(Token::TokenType::Mul);
			result *= factor();
		}
		else if (token.getType() == Token::TokenType::Div)
		{
			eat(Token::TokenType::Div);
			result /= factor();
		}
	}

	return result;
}

void Parser::error()
{
	throw std::exception("Invalid syntax");
}



