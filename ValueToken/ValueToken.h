#ifndef VALUETOKEN_H
# define VALUETOKEN_H

#include <memory>
#include "IToken/IToken.h"
#include "IOperand/IOperand.h"

class ValueToken : public IToken
{
public:
	ValueToken();
	ValueToken(const ValueToken& src);
	~ValueToken();
	ValueToken& operator=(const ValueToken& rhs);
	TokenType getType() const override;
	std::shared_ptr<IOperand> getContent() const;
private:
};

#endif
