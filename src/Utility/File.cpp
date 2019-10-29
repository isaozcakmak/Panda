#include <Utility/File.h>
#include <iostream>

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

		m_file.open(m_filePath, std::ios::in);

		if (m_file.is_open())
		{
			std::string line;
			while ( std::getline(m_file, line) )
			{
				std::cout << line << std::endl;
			}
			m_file.close();
		}
		else
		{
			std::cout << m_filePath << " file is not open" << std::endl;
		}

	}
}
