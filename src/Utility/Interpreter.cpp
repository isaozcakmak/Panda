#include <Utility/Interpreter.h>
#include <iostream>

namespace Utility
{
	Interpreter::Interpreter(const std::string code) :
		m_code(code)
	{
	}

	void Interpreter::run()
	{
		Utility::Command command = getCommand();

		switch (command)
		{
		case Utility::Command::print:
			std::cout << getPrintString() << std::endl;
			break;
		default:
			break;
		}

	}

	Utility::Command Interpreter::getCommand()
	{
		std::string commandStr = m_code.substr(0, m_code.find_first_of(' '));
		Utility::Command command = Utility::Command::unknown;

		if (commandStr == "print")
		{
			command = Utility::Command::print;
		}

		return command;
	}

	std::string Interpreter::getPrintString()
	{
		std::string str = "";

		for (size_t i = m_code.find_first_of('"'); i < m_code.find_last_of('"'); i++)
		{
			if ( m_code[i] != '"' )
			{
				str += m_code[i];
			}
		}
		
		return str;
	}

}