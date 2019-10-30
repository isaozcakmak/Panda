#include <iostream>
#include <string>
#include <Utility/File.h>

int main(int argc, char* argv[])
{
	std::string filePath = "";
	if ( argc > 1 )
	{
		filePath = argv[1];
	}

	if ( filePath.empty() )
	{
		std::cout << "File path is necessary" << std::endl;
	}
	else
	{
		Utility::File file(filePath, true);
	}

	return 0;
}