#include "ValueOverflowException.h"

const char* ValueOverflowException::what() const
{
	return "Overflow of value";
}
