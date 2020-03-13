#include "ModuloByZeroException.h"

const char* ModuloByZeroException::what() const
{
	return "Modulo by zero";
}
