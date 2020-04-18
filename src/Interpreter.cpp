#include <Interpreter.h>
#include <iostream>

Interpreter::Interpreter(Lexer lexer) :
	m_lexer(lexer),
	m_currentToken(m_lexer.getNextToken())
{
}

int Interpreter::expr()
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

void Interpreter::eat(Token::TokenType tokenType)
{
	if (m_currentToken.getType() == tokenType)
		m_currentToken = m_lexer.getNextToken();
	else
		error();
}

int Interpreter::factor()
{
	auto token = m_currentToken;
	eat(Token::TokenType::Integer);
	return token.getValue();
}

int Interpreter::term()
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

void Interpreter::error()
{
	throw std::exception("Invalid syntax");
}



