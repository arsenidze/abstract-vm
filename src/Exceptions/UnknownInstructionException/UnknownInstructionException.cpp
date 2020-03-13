#include "UnknownInstructionException.h"

const char* UnknownInstructionException::what() const
{
	return "Instruction is unknown";
}
