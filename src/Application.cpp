#include <iostream>
#include <string>
#include <Utility/File.h>
#include <Utility/Logger.h>
#include <Utility/HelperMethods.h>
#include <Interpreter.h>
#include <Lexer.h>
#include <Parser.h>

int main(int argc, char* argv[])
{
	Utility::Logger::Initialize();
	std::string filePath = "";
	if ( argc > 1 )
	{
		filePath = argv[1];
	}

	#ifdef SPI_DEBUG
		filePath = ".\\test\\test.pas";
	#endif // SPI_DEBUG

	if ( filePath.empty() )
	{
		std::cout << "File path is necessary" << std::endl;
		Log("File path is necessary");
	}
	else
	{
		try
		{
			Utility::HelperMethods::Initialize();
			Utility::File file(filePath, false);
			auto data = file.readAllText();
			Log(filePath + " successfully read");

			Lexer lexer(data);
			Log("Lexer object successfully created");

			Parser parser(lexer);
			Log("Parser object successfully created");

			Interpreter interpreter(parser);
			Log("Interpreter object successfully created");

			interpreter.interpret();
			Log("Interpreter successfully interpreted");

		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			Log(e.what());
		}
		catch (...)
		{
			std::cout << "Unknown Exception" << std::endl;
			Log("Unknown Exception");
		}

	}

	return 0;
}