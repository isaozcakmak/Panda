#include "HelperMethods.h"

namespace Utility
{
	HelperMethods::HelperMethods()
	{
	}

	void HelperMethods::toLower(std::string& data)
	{
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	}
}