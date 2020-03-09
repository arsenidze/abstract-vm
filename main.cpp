#include <iostream>
#include <string>

#include "Evaluator/Evaluator.h"
#include "Exceptions/NoExitException/NoExitException.h"
#include "Lexer/Lexer.h"
#include "Parser/Parser.h"
#include "Reader/Reader.h"

const std::string FILE_NAME = "input.txt";

int main(int argc, const char *argv[])
{
	std::string	line;
	Reader		reader;
	Lexer		lexer;
	Parser		parser;
	Evaluator	evaluator;

	if (argc == 1)
	{
		reader.open(eInputType::StandardInput);
	}
	else if (argc == 2)
	{
		reader.open(eInputType::File, argv[1]);
	}
	else
	{
		std::cerr << std::string(argv[0]) + std::string(": Too many arguments") << std::endl;
	}

	while (reader.getLine(line))
	{
		if (line.empty())
		{
			continue;
		}
		
		try
		{
			const auto tokens = lexer.getTokens(line);
			const auto ast = parser.parse(tokens);
			evaluator.evaluate(ast);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	
	try
	{
		if (reader.getInputType() == eInputType::File)
		{
			evaluator.exitCheck();
		}
	}
	catch (NoExitException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	system("pause");
	return 0;
}