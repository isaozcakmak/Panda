#ifndef PANDA_UTILITY_COMMAND
#define PANDA_UTILITY_COMMAND

namespace Utility
{
	enum class Command
	{
		// Math
		plus = 0x01,
		minus,
		mul,
		div,


		print = 0x06,
		


		unknown = 0xFF
	};
}

#endif // PANDA_UTILITY_COMMAND