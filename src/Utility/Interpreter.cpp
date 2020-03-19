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

		int rightValue = getDigit(m_code[0].at(0));
		Utility::Command operatorValue = getOperator(m_code[0].at(1));
		int leftValue = getDigit(m_code[0].at(2));

		std::cout << rightValue + leftValue << std::endl;

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