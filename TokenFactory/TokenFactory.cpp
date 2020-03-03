#include <utility>

#include "TokenFactory.h"
#include "InstructionToken/InstructionToken.h"
#include "ValueToken/ValueToken.h"
#include "CommentToken/CommentToken.h"

TokenFactory::TokenFactory()
{
}

TokenFactory::TokenFactory(const TokenFactory& src)
{
	*this = src;
}

TokenFactory::~TokenFactory()
{
}

TokenFactory& TokenFactory::operator=(const TokenFactory& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

std::shared_ptr<IToken> TokenFactory::createToken(eTokenType type, const std::string& content)
{
	switch (type)
	{
    case Instruction:
        return std::make_shared<InstructionToken>(std::move(content));
        break;
    case Value:
        return std::make_shared<ValueToken>(std::move(content));
        break;
    case Comment:
        return std::make_shared<CommentToken>(std::move(content));
        break;
    default:
        return nullptr;
        break;
	}
}