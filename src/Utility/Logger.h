#ifndef PANDA_UTILITY_LOGGER
#define PANDA_UTILITY_LOGGER

#include <Utility/File.h>
#include <string>

#define Log(message) \
	Utility::Logger::Instance().add(__FUNCTION__, size_t(__LINE__), message)

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

		void add(const std::string& function, size_t line, const std::string& message);

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