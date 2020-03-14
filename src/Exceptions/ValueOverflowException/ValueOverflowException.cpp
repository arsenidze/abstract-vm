#include "ValueOverflowException.h"

ValueOverflowException::ValueOverflowException()
	:std::runtime_error("")
{
}

const char* ValueOverflowException::what() const
{
	return "Overflow of value";
}
