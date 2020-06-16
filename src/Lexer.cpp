#include "Lexer.h"

Lexer::Lexer(const std::string code) :
	m_code(code),
	m_position(0)
{
	if (m_code.size() > 0)
		m_currentChar = m_code[m_position];
	else
		m_currentChar = NULL;

	m_reservedKeywords["begin"] = Token(Token::TokenType::Begin);
	m_reservedKeywords["end"] = Token(Token::TokenType::End);
	m_reservedKeywords["program"] = Token(Token::TokenType::Program);
	m_reservedKeywords["var"] = Token(Token::TokenType::Var);
	m_reservedKeywords["div"] = Token(Token::TokenType::IntegerDiv);
	m_reservedKeywords["integer"] = Token(Token::TokenType::Integer);
	m_reservedKeywords["real"] = Token(Token::TokenType::Real);
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

		if (m_currentChar == '{')
		{
			advance();
			skipComment();
			continue;
		}

		if (std::isalpha(m_currentChar))
			return id();

		if (std::isdigit(m_currentChar))
			return number();

		if (m_currentChar == ':' && peek() == '=')
		{
			advance();
			advance();
			return Token(Token::TokenType::Assign);
		}

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
			return Token(Token::TokenType::FloatDiv);
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

		if (m_currentChar == ';')
		{
			advance();
			return Token(Token::TokenType::Semi);
		}

		if (m_currentChar == '.')
		{
			advance();
			return Token(Token::TokenType::Dot);
		}

		if (m_currentChar == ':')
		{
			advance();
			return Token(Token::TokenType::Colon);
		}

		if (m_currentChar == ',')
		{
			advance();
			return Token(Token::TokenType::Comma);
		}

		error();
	}

	return Token(Token::TokenType::TokenEOF);
}

void Lexer::advance()
{
	m_position++;

	if (m_position > m_code.size() - 1)
		m_currentChar = NULL;
	else
		m_currentChar = m_code[m_position];

}

char Lexer::peek()
{
	int peekPosition = m_position + 1;

	if (peekPosition > m_code.size() - 1)
		return NULL;
	else
		return m_code[peekPosition];
}

void Lexer::skipWhiteSpace()
{
	while (m_currentChar != NULL && std::isspace(m_currentChar))
	{
		advance();
	}
}

void Lexer::skipComment()
{
	while (m_currentChar != '}')
	{
		advance();
	}

	advance();
}

Token Lexer::number()
{
	std::string number = "";
	while (m_currentChar != NULL && std::isdigit(m_currentChar))
	{
		number += m_currentChar;
		advance();
	}

	if (m_currentChar == '.')
	{
		number += m_currentChar;
		advance();

		while (m_currentChar != NULL && std::isdigit(m_currentChar))
		{
			number += m_currentChar;
			advance();
		}

		double doubleNumber = number.empty() ? 0.0 : std::stod(number);
		return Token(Token::TokenType::RealConst, doubleNumber);
	}

	int integerNumber = number.empty() ? 0 : std::stoi(number);
	return Token(Token::TokenType::IntegerConst, integerNumber);
}

Token Lexer::id()
{
	std::string result = "";

	while (m_currentChar != NULL && std::isalnum(m_currentChar))
	{
		result += m_currentChar;
		advance();
	}

	Utility::HelperMethods::Instance().toLower(result);

	if (m_reservedKeywords.contains(result))
		return m_reservedKeywords[result];
	else
		return Token(Token::TokenType::ID, result);
}

void Lexer::error()
{
	throw std::exception("Invalid character");
}
