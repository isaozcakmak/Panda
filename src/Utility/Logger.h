#ifndef PANDA_UTILITY_LOGGER
#define PANDA_UTILITY_LOGGER

#include <Utility/File.h>
#include <string>

namespace Utility
{
	class Logger
	{
	public:
		static void Initialize()
		{
			Instance();
			logFilePath();
		}

		static Logger& Instance()
		{
			static Logger instance;
			return instance;
		}

	private:
		Logger();
		std::string getClock();
		std::string getDate();
		std::string getProgramClock();
		std::string convertClockToString(int hour, int minute, int second);

		static const std::string& logFilePath()
		{
			static const std::string path = "Data/user.log";
			return path;
		}

	private:
		File m_file = File(logFilePath(), true);

	};
}
#endif // PANDA_UTILITY_LOGGER