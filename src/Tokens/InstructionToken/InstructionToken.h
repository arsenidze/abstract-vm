#ifndef INSTRUCTIONTOKEN_H
# define INSTRUCTIONTOKEN_H

#include <string>
#include "Tokens/IToken/IToken.h"
#include "eInstruction/eInstruction.h"

class InstructionToken : public IToken
{
public:
    InstructionToken(const std::string& value);
    InstructionToken() = delete;
    InstructionToken(const InstructionToken& src) = default;
    ~InstructionToken() = default;
    InstructionToken& operator=(const InstructionToken & rhs) = default;
    InstructionToken(InstructionToken&&) = default;
    InstructionToken& operator=(InstructionToken&&) = default;
	
	eTokenType getType() const override;
	eInstruction getContent() const;
private:
	std::string strRepresentation;
	eInstruction content;
};

#endif
