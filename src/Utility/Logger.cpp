#include <Utility/Logger.h>
#include <Utility/Clock.h>
#include <Utility/Date.h>

#include <chrono>
#include <ctime>

namespace Utility
{
	void Logger::add(const std::string& function, size_t line, const std::string& message)
	{
		std::string logMessage = message +
			" {" + function + "::" + std::to_string(line) + "}" +
			" [" + Clock::ProgramClock().toString() + "]";

		m_file.writeLine(logMessage);
	}

	Logger::Logger()
	{
		std::string logMessage = "\r\n-------------------------------------------------------\r\n\r\n";
		logMessage += "SPI - " + Date::Now().toString() + " " + Clock::Now().toString() + "\r\n";
		
		m_file.writeLine(logMessage);
	}

}
