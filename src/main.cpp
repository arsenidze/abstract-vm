#include <iostream>
#include <string>
#include <thread>
#include <sstream>

#include "Evaluator/Evaluator.h"
#include "Exceptions/DivisionByZeroException/DivisionByZeroException.h"
#include "Exceptions/FalseAssertException/FalseAssertException.h"
#include "Exceptions/InstructionOnEmptyStackException/InstructionOnEmptyStackException.h"
#include "Exceptions/InstructionsAfterExitException/InstructionsAfterExitException.h"
#include "Exceptions/InvalidValueException/InvalidValueException.h"
#include "Exceptions/LexicalErrorException/LexicalErrorException.h"
#include "Exceptions/ModuloByZeroException/ModuloByZeroException.h"
#include "Exceptions/NoExitException/NoExitException.h"
#include "Exceptions/NotEnoughOperandsException/NotEnoughOperandsException.h"
#include "Exceptions/SyntaxErrorException/SyntaxErrorException.h"
#include "Exceptions/UnknownInstructionException/UnknownInstructionException.h"
#include "Exceptions/ValueOverflowException/ValueOverflowException.h"
#include "Exceptions/ValueUnderflowException/ValueUnderflowException.h"
#include "Lexer/Lexer.h"
#include "Parser/Parser.h"
#include "Reader/Reader.h"

static std::string formOutputErrorMessage(const std::string& line, size_t lineNumber, const std::string& description, const std::string& type = "Error")
{
	if (!line.empty())
	{
		return "Line " + std::to_string(lineNumber) + " : " + type + " : " + "'" + line + "'" + " : " + description;
	}
	return "Line " + std::to_string(lineNumber) + " : " + type + " : " + description;
}

void abstract_vm(eInputType type = eInputType::StandardInput, const char * fileName = "", std::ostream& output = std::cout)
{
	std::string	line;
	Reader		reader;
	Lexer		lexer;
	Parser		parser;
	Evaluator	evaluator(output);

	if (!reader.open(type, fileName))
	{
		output << "Error: Can't open file" << std::endl;
		return;
	}

	std::vector<std::string>	errorList;
	for (size_t numOfLines = 1; reader.getLine(line); numOfLines++)
	{
		if (line.empty())
		{
			continue;
		}

		try
		{
			const auto tokens = lexer.getTokens(line);
			const auto ast = parser.parse(tokens);
			
			if (errorList.empty())
			{
				evaluator.evaluate(ast);
			}
		}
		catch (const DivisionByZeroException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const FalseAssertException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const InstructionOnEmptyStackException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const InstructionsAfterExitException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const InvalidValueException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const LexicalErrorException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const ModuloByZeroException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const NotEnoughOperandsException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const SyntaxErrorException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const UnknownInstructionException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const ValueOverflowException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const ValueUnderflowException & ex)
		{
			errorList.emplace_back(formOutputErrorMessage(line, numOfLines, ex.what()));
		}
		catch (const std::exception& ex)
		{
			output << "Unexpected error: " << ex.what() << std::endl;
			return;
		}
	}

	if (!errorList.empty())
	{
		for (const auto& error : errorList)
		{
			output << error << std::endl;
		}
		return;
	}
	
	try
	{
		evaluator.exitCheck();
	}
	catch (const NoExitException & ex)
	{
		output << std::string("Error: ") + ex.what() << std::endl;
	}
}

int main(const int argc, const char *argv[])
{
	if (argc == 1)
	{
		abstract_vm(eInputType::StandardInput);
	}
	else if (argc == 2 && (std::string(argv[1]) == "--help"))
	{
		std::cout << std::string("Usage: ") + std::string(argv[0]) + std::string(" <input file1> <input file2> ... <input fileN>") << std::endl;
	}
	else
	{
		std::vector<std::thread>	threads;
		std::vector<std::string>	outputStrs(argc - 1, "");
		
		for (int i = 1; i < argc; ++i)
		{
			auto singleThread = [](const char * fileName, std::string& outputStr) -> void
			{
				std::ostringstream output;
				
				output << std::string(fileName) + std::string(":") << std::endl << std::endl;
				abstract_vm(eInputType::File, fileName, output);
				output << std::string(80, '-') << std::endl << std::endl;

				outputStr = output.str();
			};
			
			threads.emplace_back(std::thread(singleThread, argv[i], std::ref(outputStrs[i - 1])));
		}

		for (size_t i = 0; i < threads.size(); i++)
		{
			if (threads[i].joinable())
			{
				threads[i].join();
				std::cout << outputStrs[i] << std::endl;
			}
		}
	}
	
	return 0;
}