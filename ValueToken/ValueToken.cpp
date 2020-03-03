#include <regex>
#include "ValueToken.h"
#include "OperandFactory/OperandFactory.h"

eOperandType strToOperandType(const std::string& value)
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
}

ValueToken::ValueToken(const std::string& value)
{
    this->strRepresentation = value;

    std::regex  re("^(int8|int16|int32)\\(([-]?[0-9]+)\\)$");
    std::smatch m;
    
    auto isMatch = std::regex_match(value, m, re);

    if (!isMatch)
    {

    }

    this->content = OperandFactory::createOperand(strToOperandType(m.str(1)), m.str(2));
}

ValueToken::ValueToken(const ValueToken& src)
{
	*this = src;
}

ValueToken::~ValueToken()
{
}

ValueToken& ValueToken::operator=(const ValueToken& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

eTokenType ValueToken::getType() const
{
    return eTokenType::Value;
}

const IOperand* ValueToken::getContent() const
{
	return this->content;
}
