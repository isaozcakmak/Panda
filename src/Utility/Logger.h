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