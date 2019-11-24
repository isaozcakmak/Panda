#ifndef PANDA_UTILITY_INTERPRETER
#define PANDA_UTILITY_INTERPRETER

#include <Utility/Command.h>
#include <string>

namespace Utility
{
	class Interpreter
	{
	public:
		Interpreter(const std::string code);
		~Interpreter() {}

		void run();

	private:
		Utility::Command getCommand();
		std::string getPrintString();

	private:
		std::string m_code;
	};
}

#endif // PANDA_UTILITY_INTERPRETER