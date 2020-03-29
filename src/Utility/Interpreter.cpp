#include <Utility/Interpreter.h>
#include <iostream>

namespace Utility
{
	Interpreter::Interpreter(const std::vector<std::string> code) :
		m_code(code)
	{
	}

	void Interpreter::run()
	{
		//Utility::Command command = getCommand();

		//switch (command)
		//{
		//case Utility::Command::print:
		//	std::cout << getPrintString() << std::endl;
		//	break;
		//default:
		//	break;
		//}

		if (m_code.size() == 0)
			return;

		if (m_code[0].empty())
			return;

		int index = 0;
		int result = getNumber(m_code[0], index);

		while (m_code[0].size() > index && isOperator(m_code[0].at(index)))
		{
			Utility::Command operatorValue = getOperator(m_code[0], index);
			int value = getNumber(m_code[0], index);
			
			switch (operatorValue)
			{
				case Utility::Command::plus:
					result += value;
					break;
				case Utility::Command::minus:
					result -= value;
					break;
				case Utility::Command::print:
					break;
				case Utility::Command::unknown:
					break;
				default:
					break;
			}

		}

		std::cout << result << std::endl;

		//int rightValue = getNumber(m_code[0], index);
		//Utility::Command operatorValue = getOperator(m_code[0], index);
		//int leftValue = getNumber(m_code[0], index);

		//int rightValue = getDigit(m_code[0].at(0));
		//Utility::Command operatorValue = getOperator(m_code[0].at(1));
		//int leftValue = getDigit(m_code[0].at(2));
		
		//switch (operatorValue)
		//{
		//	case Utility::Command::plus:
		//		std::cout << rightValue + leftValue << std::endl;
		//		break;
		//	case Utility::Command::minus:
		//		std::cout << rightValue - leftValue << std::endl;
		//		break;
		//	case Utility::Command::print:
		//		break;
		//	case Utility::Command::unknown:
		//		break;
		//	default:
		//		break;
		//}

	}

	int Interpreter::getNumber(std::string value, int& index)
	{
		std::string number = "";
		while (value.length() > index)
		{
			if (std::isspace(value.at(index)))
			{
				skipWhitespace(index);
				continue;
			}
			
			if (std::isdigit(value.at(index)))
				//number.append(&value.at(index++));
				number += value.at(index++);
			else
				break;
		}

		return number.empty() ? 0 : std::stoi(number);
	}

	Utility::Command Interpreter::getOperator(std::string value, int& index)
	{
		while (value.length() > index)
		{
			if (std::isspace(value.at(index)))
			{
				skipWhitespace(index);
				continue;
			}

			return getOperator(value.at(index++));
		}

		return Utility::Command::unknown;
	}

	void Interpreter::skipWhitespace(int& index)
	{
		index++;
	}

	int Interpreter::getDigit(char value)
	{
		if (std::isdigit(value))
		{
			return std::stoi(std::string(&value));
		}

		return 0;
	}

	Utility::Command Interpreter::getOperator(char value)
	{
		switch (value)
		{
			case '+':
				return Utility::Command::plus;
				break;
			case '-':
				return Utility::Command::minus;
				break;
			default:
				return Utility::Command::unknown;
				break;
		}

	}

	bool Interpreter::isOperator(char value)
	{
		switch (value)
		{
		case '+':
		case '-':
			return true;
			break;
		default:
			return false;
			break;
		}

	}

	//Utility::Command Interpreter::getCommand()
	//{
	//	std::string commandStr = m_code.substr(0, m_code.find_first_of(' '));
	//	Utility::Command command = Utility::Command::unknown;

	//	if (commandStr == "print")
	//	{
	//		command = Utility::Command::print;
	//	}

	//	return command;
	//}

	//std::string Interpreter::getPrintString()
	//{
	//	std::string str = "";

	//	for (size_t i = m_code.find_first_of('"'); i < m_code.find_last_of('"'); i++)
	//	{
	//		if ( m_code[i] != '"' )
	//		{
	//			str += m_code[i];
	//		}
	//	}
	//	
	//	return str;
	//}

}