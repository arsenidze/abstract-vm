// abstract-vm.cpp : Defines the entry point for the application.
//

#include <string>
#include "abstract-vm.h"
#include "Reader/Reader.h"
#include "Lexer/Lexer.h"
//#include "Parser/Parser.h"
//#include "Evaluator/Evaluator.h"

const std::string FILE_NAME = "input.txt";

int main()
{
	std::string	line;
	Reader		reader;
	Lexer		lexer;
	//Parser		parser;
	//Evaluator	evaluator;

	reader.open(FILE_NAME);
	
	while (!((line = reader.getLine()).empty()))
	{
		std::cout << line << std::endl;
		auto tokens = lexer.getTokens(line);
		//try
		//{
		//	auto tokens = lexer.getTokens(line);
		//	auto ast = parser.parse(tokens);
		//	evaluator.evaluate(ast);
		//}
		//catch (const std::exception&)
		//{

		//}
	}
	std::cout << "Hello CMake." << std::endl;
	return 0;
}
