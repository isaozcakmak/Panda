#include "Lexer.h"

Lexer::Lexer(const std::vector<std::string> code) :
	m_code(code),
	m_index(0),
	m_position(0)
{
	if (m_code.size() > 0 && m_code[m_index].size() > 0)
		m_currentChar = m_code[m_index][m_position];
	else
		m_currentChar = NULL;
}

Token Lexer::getNextToken()
{
	while (m_currentChar != NULL)
	{
		if (std::isspace(m_currentChar))
		{
			skipWhiteSpace();
			continue;
		}

		if (std::isdigit(m_currentChar))
			return Token(Token::TokenType::Integer, integer());

		if (m_currentChar == '+')
		{
			advance();
			return Token(Token::TokenType::Plus);
		}

		if (m_currentChar == '-')
		{
			advance();
			return Token(Token::TokenType::Minus);
		}

		if (m_currentChar == '*')
		{
			advance();
			return Token(Token::TokenType::Mul);
		}

		if (m_currentChar == '/')
		{
			advance();
			return Token(Token::TokenType::Div);
		}
		
		if (m_currentChar == '(')
		{
			advance();
			return Token(Token::TokenType::LeftParenthesis);
		}

		if (m_currentChar == ')')
		{
			advance();
			return Token(Token::TokenType::RightParenthesis);
		}

		error();
	}

	return Token(Token::TokenType::TokenEOF);
}

void Lexer::advance()
{
	m_position++;

	if (m_position > m_code[m_index].size() - 1)
		m_currentChar = NULL;
	else
		m_currentChar = m_code[m_index][m_position];

}

void Lexer::skipWhiteSpace()
{
	while (m_currentChar != NULL && std::isspace(m_currentChar))
	{
		advance();
	}
}

int Lexer::integer()
{
	std::string number = "";
	while (m_currentChar != NULL && std::isdigit(m_currentChar))
	{
		number += m_currentChar;
		advance();
	}

	return number.empty() ? 0 : std::stoi(number);
}

void Lexer::error()
{
	throw std::exception("Invalid character");
}
