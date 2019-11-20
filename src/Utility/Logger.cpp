#include <Utility/Logger.h>
#include <Utility/Clock.h>

#include <chrono>
#include <ctime>

namespace Utility
{
	static auto g_ProgramStart = std::chrono::system_clock::now();

	Logger::Logger()
	{
		std::string logMessage = "\r\n-------------------------------------------------------\r\n\r\n";
		logMessage += "Panda - " + getDate() + " " + Clock::Now().ToString() + "\r\n";
		
		m_file.writeLine(logMessage);
	}

	std::string Logger::getDate()
	{
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);
		auto tmDate = std::localtime(&now_c);

		std::string day = std::to_string(tmDate->tm_mday);
		std::string month = std::to_string(tmDate->tm_mon + 1);
		std::string year = std::to_string(tmDate->tm_year + 1900);

		if (day.size() < 2)
		{
			day = "0" + day;
		}
		if (month.size() < 2)
		{
			month = "0" + month;
		}

		return day + "." + month + "." + year;
	}

	std::string Logger::getProgramClock()
	{
		auto now = std::chrono::system_clock::now();
		auto programDuration = now - g_ProgramStart;

		auto hour = std::chrono::duration_cast<std::chrono::hours>(programDuration);
		auto minute = std::chrono::duration_cast<std::chrono::minutes>(programDuration);
		auto second = std::chrono::duration_cast<std::chrono::seconds>(programDuration);

		return convertClockToString(hour.count(), minute.count() % 60, second.count() % 60);
	}

	std::string Logger::convertClockToString(int hour, int minute, int second)
	{
		std::string hourString = std::to_string(hour);
		std::string minuteString = std::to_string(minute);
		std::string secondString = std::to_string(second);

		if (hourString.size() < 2)
		{
			hourString = "0" + hourString;
		}
		if (minuteString.size() < 2)
		{
			minuteString = "0" + minuteString;
		}
		if (secondString.size() < 2)
		{
			secondString = "0" + secondString;
		}

		return hourString + ":" + minuteString + ":" + secondString;
	}
}
