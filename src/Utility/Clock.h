#ifndef PANDA_UTILITY_CLOCK
#define PANDA_UTILITY_CLOCK

namespace Utility
{
	class Clock
	{
	public:
		Clock(int hours, int minute, int second);
		~Clock();

	private:
		int m_hours;
		int m_minute;
		int m_second;

	};
}

#endif // PANDA_UTILITY_CLOCK