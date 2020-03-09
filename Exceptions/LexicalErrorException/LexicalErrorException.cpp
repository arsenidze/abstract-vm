#include "LexicalErrorException.h"

const char* LexicalErrorException::what() const
{
	return "Lexical error";
}
