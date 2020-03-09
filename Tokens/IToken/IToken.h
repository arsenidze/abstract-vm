#ifndef ITOKEN_H
# define ITOKEN_H

#include "eTokenType/eTokenType.h"

class IToken
{
public:
	virtual ~IToken() {}
	virtual eTokenType getType() const = 0;
private:
};

#endif
