#include "DivisionByZeroException.h"

const char* DivisionByZeroException::what() const
{
	return "Division by zero";
}
