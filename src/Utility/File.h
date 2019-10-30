#ifndef PANDA_UTILITY_FILE
#define PANDA_UTILITY_FILE

#include <fstream>
#include <string>

namespace Utility
{
	class File
	{
	public:
		File(const std::string& filePath, bool create = false);
		~File();
		std::string readLine();
		void writeLine(const std::string& data);

	public:
		File(const File& other) = delete;

	private:
		std::string m_filePath;
		std::fstream m_file;
	};
}

#endif // PANDA_UTILITY_FILE