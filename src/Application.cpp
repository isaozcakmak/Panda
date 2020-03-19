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
		filePath = ".\\bin\\x64\\Debug\\test.pnd";
	#endif // PANDA_DEBUG

	if ( filePath.empty() )
	{
		std::cout << "File path is necessary" << std::endl;
	}
	else
	{
		Utility::Logger::Initialize();
		Utility::File file(filePath, false);
		//std::string line = file.readLine();
		auto data = file.readAllFile();
		Utility::Interpreter interpreter(data);
		interpreter.run();
	}

	return 0;
}