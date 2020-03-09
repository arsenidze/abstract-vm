#include "FalseAssertException.h"

const char* FalseAssertException::what() const
{
	return "Assert is not true";
}
