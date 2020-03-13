#ifndef VALUETOKEN_H
# define VALUETOKEN_H

#include <string>
#include "Tokens/IToken/IToken.h"
#include "IOperand/IOperand.h"

class ValueToken : public IToken
{
public:
    ValueToken(const std::string& value);
    ValueToken() = delete;
    ValueToken(const ValueToken& src) = default;
    ~ValueToken() = default;
    ValueToken& operator=(const ValueToken & rhs) = default;
    ValueToken(ValueToken&&) = default;
    ValueToken& operator=(ValueToken&&) = default;
	
	eTokenType getType() const override;
	const IOperand * getContent() const;
private:
	std::string strRepresentation;
	const IOperand* content;
	eOperandType strToOperandType(const std::string& value) const;
};

#endif
