#include "ValueToken.h"

#include <regex>

#include "Exceptions/InvalidValueException/InvalidValueException.h"
#include "OperandFactory/OperandFactory.h"
#include "Util/Conversion/Conversion.h"

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

    this->content = OperandFactory::createOperand(Util::Conversion::strToOperandType(m.str(1)), m.str(2));
}

eTokenType ValueToken::getType() const
{
    return eTokenType::Value;
}

const IOperand* ValueToken::getContent() const
{
	return this->content;
}