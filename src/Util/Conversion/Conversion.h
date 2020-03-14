#ifndef CONVERSION_H
# define CONVERSION_H

#include <string>

#include "eOperandType/eOperandType.h"

namespace Util
{
	namespace Conversion
	{
		std::string	operandTypeToStr(eOperandType type);
		eOperandType strToOperandType(const std::string& value);
	}
}

#endif
