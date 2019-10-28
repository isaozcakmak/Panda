#ifndef PANDA_UTILITY_FILE
#define PANDA_UTILITY_FILE

#include <string>

namespace Utility
{
	class File
	{
	public:
		File(const std::string& filePath);

	public:
		File(const File& other) = delete;

	private:
		std::string m_filePath;
	};
}

#endif // PANDA_UTILITY_FILE