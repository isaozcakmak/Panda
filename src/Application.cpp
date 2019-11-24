#include <iostream>
#include <string>
#include <Utility/File.h>
#include <Utility/Logger.h>
#include <Utility/Interpreter.h>

int main(int argc, char* argv[])
{
	std::string filePath = "";
	if ( argc > 1 )
	{
		filePath = argv[1];
	}

	#ifdef PANDA_DEBUG
		filePath = "D:\\Workspaces\\VS2019\\Panda\\bin\\x64\\Debug\\test.txt";
	#endif // PANDA_DEBUG

	if ( filePath.empty() )
	{
		std::cout << "File path is necessary" << std::endl;
	}
	else
	{
		Utility::Logger::Initialize();
		Utility::File file(filePath, false);
		std::string line = file.readLine();
		Utility::Interpreter interpreter(line);
		interpreter.run();
	}

	return 0;
}