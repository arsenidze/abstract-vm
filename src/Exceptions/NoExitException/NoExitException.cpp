#include "NoExitException.h"

const char* NoExitException::what() const
{
	return "The program doesn't have an exit instruction";
}
