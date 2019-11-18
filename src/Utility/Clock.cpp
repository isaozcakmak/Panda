#include "Clock.h"

#include <chrono>
#include <ctime>

namespace Utility
{
	Clock::Clock(int hour, int minute, int second) : 
		m_hour(hour), m_minute(minute), m_second(second)
	{
	}
	const std::string Clock::Now()
	{
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);
		auto tmDate = std::localtime(&now_c);

		return std::string();
	}
	const std::string Clock::ToString() const
	{
		return std::string();
	}
}