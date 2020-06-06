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
		filePath = ".\\test\\test.pnd";
	#endif // PANDA_DEBUG

	if ( filePath.empty() )
	{
		std::cout << "File path is necessary" << std::endl;
	}
	else
	{
		try
		{
			Utility::Logger::Initialize();
			Utility::File file(filePath, false);
			auto data = file.readAllText();
			Lexer lexer(data);
			Parser parser(lexer);
			Interpreter interpreter(parser);
			interpreter.interpret();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Unknown Exception" << std::endl;
		}

	}

	return 0;
}