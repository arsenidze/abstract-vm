#include "Conversion.h"

#include <stdexcept>

std::string Util::Conversion::operandTypeToStr(eOperandType type)
{
	switch (type)
	{
    case Int8:
        return "Int8";
    case Int16:
        return "Int16";
    case Int32:
        return "Int32";
    case Float:
        return "Float";
    case Double:
        return "Double";
	default:
        throw std::logic_error("Unknown type of operand");
	}
}

eOperandType Util::Conversion::strToOperandType(const std::string& value)
{
    if (value == "int8")
    {
        return eOperandType::Int8;
    }
    else if (value == "int16")
    {
        return eOperandType::Int16;
    }
    else if (value == "int32")
    {
        return eOperandType::Int32;
    }
    else if (value == "float")
    {
        return eOperandType::Float;
    }
    else if (value == "double")
    {
        return eOperandType::Double;
    }
    throw std::logic_error("Unknown type of operand");
}
