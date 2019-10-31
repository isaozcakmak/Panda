#ifndef PANDA_UTILITY_LOGGER
#define PANDA_UTILITY_LOGGER

namespace Koala::Utility
{
	class Logger
	{
	public:
		static Logger& Instance()
		{
			static Logger instance;
			return instance;
		}

	private:
		Logger();
	};
}
#endif // PANDA_UTILITY_LOGGER