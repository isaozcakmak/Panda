#ifndef PANDA_UTILITY_DATE
#define PANDA_UTILITY_DATE

#include <string>

namespace Utility
{
	class Date
	{
	public:
		Date(size_t day, size_t month, size_t year);
		~Date() {}

		static const Date Now();

		const std::string toString() const;

		operator const std::string() const;

	private:
		size_t m_day = 1;
		size_t m_month = 1;
		size_t m_year = 1970;

	};
}

#endif // PANDA_UTILITY_DATE