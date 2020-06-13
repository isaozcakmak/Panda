#ifndef PANDA_HELPERMETHODS_CLOCK
#define PANDA_HELPERMETHODS_CLOCK

#include <string>
#include <algorithm>

namespace Utility
{
	class HelperMethods
	{
	public:
		~HelperMethods() {}

		static void Initialize()
		{
			Instance();
		}

		static HelperMethods& Instance()
		{
			static HelperMethods instance;
			return instance;
		}

		void toLower(std::string& data);

	private:
		HelperMethods();

	};
}

#endif // PANDA_UTILITY_CLOCK