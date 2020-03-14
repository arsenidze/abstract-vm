#include "InstructionsAfterExitException.h"

const char* InstructionsAfterExitException::what() const
{
	return "Division by zero";
}
