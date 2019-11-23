#include <Utility/Date.h>

#include <chrono>
#include <ctime>

namespace Utility
{
	Date::Date(size_t day, size_t month, size_t year) :
		m_day(day), m_month(month), m_year(year)
	{
	}

	const Date Date::Now()
	{
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);
		auto tmDate = std::localtime(&now_c);

		return Date(tmDate->tm_mday, tmDate->tm_mon + 1, tmDate->tm_year + 1900);
	}

	Date::operator const std::string() const
	{
		std::string day = std::to_string(m_day);
		std::string month = std::to_string(m_month);
		std::string year = std::to_string(m_year);

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

	const std::string Date::toString() const
	{
		return *this;
	}

}