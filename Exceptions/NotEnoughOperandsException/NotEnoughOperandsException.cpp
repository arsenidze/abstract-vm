#include "NotEnoughOperandsException.h"

const char* NotEnoughOperandsException::what() const
{
	return "Not enough values on the stack";
}
