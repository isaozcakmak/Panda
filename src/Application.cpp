#include <iostream>
#include <string>
#include <Utility/File.h>
#include <Utility/Logger.h>
#include <Interpreter.h>
#include <Lexer.h>
#include <Parser.h>

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
		Lexer lexer(data);
		Parser parser(lexer);
		Interpreter interpreter(lexer);
		auto result = interpreter.interpret();
		std::cout << result << std::endl;
	}

	return 0;
}