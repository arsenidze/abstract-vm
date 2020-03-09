#include "Parser.h"

#include "EvaluationStructure/EvaluationStructure.h"
#include "Exceptions/SyntaxErrorException/SyntaxErrorException.h"
#include "Tokens/CommentToken/CommentToken.h"
#include "Tokens/InstructionToken/InstructionToken.h"
#include "Tokens/ValueToken/ValueToken.h"

const size_t Parser::MAX_NUMBER_OF_TOKENS_IN_SENTECE = 3;

std::shared_ptr<IAST> Parser::parse(std::vector<std::shared_ptr<IToken>> tokens)
{
    if (tokens.size() > this->MAX_NUMBER_OF_TOKENS_IN_SENTECE)
    {
        throw SyntaxErrorException();
    }
	
    std::shared_ptr<EvaluationStructure>    res = std::make_shared<EvaluationStructure>();

    int8_t offsetIfComment = 0;
    if (tokens.back()->getType() == eTokenType::Comment)
    {
        auto commentToken = std::static_pointer_cast<CommentToken>(tokens[0]);
        res->comment = commentToken->getContent();
    	if (tokens.size() == 1)
    	{
            return res;
    	}
        offsetIfComment = 1;
    }

    if (tokens[0]->getType() != eTokenType::Instruction)
    {
        throw SyntaxErrorException();
    }

    auto instructionToken = std::static_pointer_cast<InstructionToken>(tokens[0]);

    if (tokens.size() == (1 - offsetIfComment))
    {
        if ((instructionToken->getContent() == eInstruction::Push) ||
            (instructionToken->getContent() == eInstruction::Assert))
        {
            throw SyntaxErrorException();
        }
        res->instruction = instructionToken->getContent();
    }
    else if ((tokens.size() == (2 - offsetIfComment)) && 
        (tokens[1]->getType() == eTokenType::Value))
    {
        if (!((instructionToken->getContent() == eInstruction::Push) ||
            (instructionToken->getContent() == eInstruction::Assert)))
        {
            throw SyntaxErrorException();
        }
        res->instruction = instructionToken->getContent();

        auto valueToken = std::static_pointer_cast<ValueToken>(tokens[1]);
        res->value = valueToken->getContent();
    }
    else
    {
        if (res->isEmpty())
        {
            throw SyntaxErrorException();
        }
    }
    
    return res;
}