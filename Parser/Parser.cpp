#include "Parser.h"
#include "EvaluationStructure/EvaluationStructure.h"
#include "CommentToken/CommentToken.h"
#include "InstructionToken/InstructionToken.h"
#include "ValueToken/ValueToken.h"

const size_t Parser::MAX_NUMBER_OF_TOKENS_IN_SENTECE = 3;

Parser::Parser()
{
}

Parser::Parser(const Parser& src)
{
	*this = src;
}

Parser::~Parser()
{
}

Parser& Parser::operator=(const Parser& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

std::shared_ptr<IAST> Parser::parse(std::vector<std::shared_ptr<IToken>> tokens)
{
    if (tokens.size() > this->MAX_NUMBER_OF_TOKENS_IN_SENTECE)
    {
        throw std::exception();
    }

    std::shared_ptr<EvaluationStructure>    res = std::make_shared<EvaluationStructure>();

    int offsetIfComment = 0;
    if (tokens.back()->getType() == eTokenType::Comment)
    {
        auto commentToken = std::static_pointer_cast<CommentToken>(tokens[0]);
        res->comment = commentToken->getContent();
        offsetIfComment = 1;
    }

    if (tokens[0]->getType() != eTokenType::Instruction)
    {
        throw std::exception();
    }

    auto instructionToken = std::static_pointer_cast<InstructionToken>(tokens[0]);

    if (tokens.size() == (1 - offsetIfComment))
    {
        if ((instructionToken->getContent() == eInstruction::Push) ||
            (instructionToken->getContent() == eInstruction::Assert))
        {
            throw std::exception();
        }
        res->instruction = instructionToken->getContent();
    }
    else if ((tokens.size() == (2 - offsetIfComment)) && 
        (tokens[1]->getType() == eTokenType::Value))
    {
        if (!((instructionToken->getContent() == eInstruction::Push) ||
            (instructionToken->getContent() == eInstruction::Assert)))
        {
            throw std::exception();
        }
        res->instruction = instructionToken->getContent();

        auto valueToken = std::static_pointer_cast<ValueToken>(tokens[1]);
        res->value = valueToken->getContent();
    }
    else
    {
        if (res->isEmpty())
        {
            throw std::exception();
        }
    }
    
    return res;
}