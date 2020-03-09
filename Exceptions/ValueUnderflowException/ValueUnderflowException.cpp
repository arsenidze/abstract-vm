#include "ValueUnderflowException.h"

const char* ValueUnderflowException::what() const
{
	return "Overflow of value";
}
