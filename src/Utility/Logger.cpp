#include <Utility/Logger.h>
#include <Utility/Clock.h>
#include <Utility/Date.h>

#include <chrono>
#include <ctime>

namespace Utility
{

	Logger::Logger()
	{
		std::string logMessage = "\r\n-------------------------------------------------------\r\n\r\n";
		logMessage += "Panda - " + Date::Now().toString() + " " + Clock::Now().toString() + "\r\n";
		
		m_file.writeLine(logMessage);
	}

}
