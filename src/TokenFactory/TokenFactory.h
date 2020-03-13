#ifndef TOKENFACTORY_H
# define TOKENFACTORY_H

#include <memory>
#include <string>

#include "eTokenType/eTokenType.h"
#include "Tokens/IToken/IToken.h"

class TokenFactory
{
public:
    TokenFactory() = delete;
    TokenFactory(const TokenFactory& src) = delete;
    ~TokenFactory() = delete;
    TokenFactory& operator=(const TokenFactory & rhs) = delete;
    TokenFactory(TokenFactory&&) = delete;
    TokenFactory& operator=(TokenFactory&&) = delete;
	
	static std::shared_ptr<IToken> createToken(eTokenType type, const std::string& content);
private:
};

#endif
