#ifndef ITOKEN_H
# define ITOKEN_H

#include "TokenType/TokenType.h"

class IToken
{
public:
	virtual ~IToken() {}
	virtual TokenType getType() const = 0;
private:
};

#endif
