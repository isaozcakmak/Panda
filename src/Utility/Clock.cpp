#include "Clock.h"

#include <chrono>
#include <ctime>

namespace Utility
{
	Clock::Clock(int hour, int minute, int second) : 
		m_hour(hour), m_minute(minute), m_second(second)
	{
	}

	const Clock Clock::Now()
	{
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);
		auto tmDate = std::localtime(&now_c);

		return Clock(tmDate->tm_hour, tmDate->tm_min, tmDate->tm_sec);
	}

	const std::string Clock::ToString() const
	{
		return *this;
	}

	Clock::operator const std::string() const
	{
		std::string hourString = std::to_string(m_hour);
		std::string minuteString = std::to_string(m_minute);
		std::string secondString = std::to_string(m_second);

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