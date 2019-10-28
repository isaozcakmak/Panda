#include <Utility/File.h>

#if defined(_WIN32) || defined(WIN32)
#include <Windows.h>
#endif

namespace Utility
{
	File::File(const std::string& filePath) : m_filePath(filePath)
	{
		if (filePath == "")
		{
			return;
		}
	}
}
