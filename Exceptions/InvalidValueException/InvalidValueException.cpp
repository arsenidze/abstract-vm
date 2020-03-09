#include "InvalidValueException.h"

const char* InvalidValueException::what() const
{
	return "Value is invalid";
}
