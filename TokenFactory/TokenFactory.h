#ifndef TOKENFACTORY_H
# define TOKENFACTORY_H

#include <string>
#include <memory>
#include "IToken/IToken.h"
#include "eTokenType/eTokenType.h"

class TokenFactory
{
public:
	TokenFactory();
	TokenFactory(const TokenFactory& src);
	~TokenFactory();
	TokenFactory& operator=(const TokenFactory& rhs);
	static std::shared_ptr<IToken> createToken(eTokenType type, const std::string& content);
private:
};

#endif
