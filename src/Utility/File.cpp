#include <Utility/File.h>
#include <Utility/Platform.h>
#include <iostream>

#if OS_WINDOWS
#include <Windows.h>
#endif

namespace Utility
{

	static bool DoesFolderExists(const std::string& path);
	static void CreateFolder(const std::string& path);

	File::File(const std::string& filePath, bool create) : m_filePath(filePath)
	{
		if (filePath == "")
		{
			return;
		}

		if ( create == false )
		{
			m_file.open(m_filePath, std::ios::in);
		}
		else
		{
			m_file.open(m_filePath, std::ios::out);

			if ( m_file.is_open() == false )
			{
				size_t folderPathIdx = m_filePath.find_last_of('/');
				if (folderPathIdx != m_filePath.npos)
				{
					CreateFolder(m_filePath.substr(0, folderPathIdx));
				}

				m_file.open(m_filePath, std::ios::out);
			}
		}

		if ( m_file.is_open() == false)
		{
			std::cout << m_filePath << " file is not open" << std::endl;
		}

	}

	File::~File()
	{
		if ( m_file.is_open() )
		{
			m_file.close();
		}
	}

	std::string File::readLine()
	{
		if ( m_file.is_open() )
		{
			std::string line = "";
			std::getline(m_file, line);
			return line;
		}
		else
		{
			return "";
		}
	}

	void File::writeLine(const std::string& data)
	{
		if ( m_file.is_open() )
		{
			m_file << data + "\r\n";
		}
	}


	static bool DoesFolderExists(const std::string& path)
	{
		bool result = false;

		#if OS_WINDOWS
			DWORD dwAttrib = GetFileAttributes(path.c_str());

			result = dwAttrib != INVALID_FILE_ATTRIBUTES &&
				(dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
		#else
		#error No implementation on this OS
		#endif

		return result;
	}
	static void CreateFolder(const std::string& path)
	{
		std::string folderPath = path;

		if (*(folderPath.rbegin()) == '/')
		{
			folderPath.erase(folderPath.end() - 1);
		}

		if (DoesFolderExists(folderPath) == false)
		{
			size_t lastSlash = folderPath.find_last_of('/');
			if (lastSlash != folderPath.npos)
			{
				CreateFolder(folderPath.substr(0, lastSlash));
			}

			#if OS_WINDOWS
				CreateDirectory(folderPath.c_str(), nullptr);
			#else
			#error No implementation on this OS
			#endif
		}
	}

}
