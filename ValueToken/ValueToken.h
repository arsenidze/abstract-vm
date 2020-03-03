#ifndef VALUETOKEN_H
# define VALUETOKEN_H

#include <string>
#include <memory>
#include "IToken/IToken.h"
#include "IOperand/IOperand.h"

class ValueToken : public IToken
{
public:
	ValueToken(const std::string& value);
	ValueToken(const ValueToken& src);
	~ValueToken();
	ValueToken& operator=(const ValueToken& rhs);
	eTokenType getType() const override;
	const IOperand * getContent() const;
private:
	std::string strRepresentation;
	const IOperand* content;
};

#endif
