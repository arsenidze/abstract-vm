#include "ValueToken.h"

#include <regex>

#include "Exceptions/InvalidValueException/InvalidValueException.h"
#include "OperandFactory/OperandFactory.h"

ValueToken::ValueToken(const std::string& value)
{
    this->strRepresentation = value;

    const std::regex  re[] = { std::regex("^(int8|int16|int32)\\(([-]?[0-9]+)\\)$"), std::regex("^(float|double)\\(([-]?[0-9]+.[0-9]+)\\)$")};
    std::smatch m;

    auto isMatch = std::regex_match(value, m, re[0]);
	
	if (!isMatch)
	{
        isMatch = std::regex_match(value, m, re[1]);
	}

	if (!isMatch)
	{
        throw InvalidValueException();
	}

    this->content = OperandFactory::createOperand(strToOperandType(m.str(1)), m.str(2));
}

eTokenType ValueToken::getType() const
{
    return eTokenType::Value;
}

const IOperand* ValueToken::getContent() const
{
	return this->content;
}

eOperandType ValueToken::strToOperandType(const std::string& value) const
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