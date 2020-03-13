#include "TokenFactory.h"

#include <stdexcept>

#include "Tokens/InstructionToken/InstructionToken.h"
#include "Tokens/ValueToken/ValueToken.h"
#include "Tokens/CommentToken/CommentToken.h"

std::shared_ptr<IToken> TokenFactory::createToken(eTokenType type, const std::string& content)
{
	switch (type)
	{
    case Instruction:
        return std::make_shared<InstructionToken>(content);
    case Value:
        return std::make_shared<ValueToken>(content);
    case Comment:
        return std::make_shared<CommentToken>(content);
    default:
        throw std::logic_error("Unknown type of token");
	}
}