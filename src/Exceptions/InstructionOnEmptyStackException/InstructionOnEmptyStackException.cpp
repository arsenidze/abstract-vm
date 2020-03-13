#include "InstructionOnEmptyStackException.h"

const char* InstructionOnEmptyStackException::what() const
{
	return "Pop on empty stack";
}
