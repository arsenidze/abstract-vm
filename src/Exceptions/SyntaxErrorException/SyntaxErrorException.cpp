#include "SyntaxErrorException.h"

const char* SyntaxErrorException::what() const
{
	return "Syntax error";
}
