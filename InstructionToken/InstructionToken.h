#ifndef INSTRUCTIONTOKEN_H
# define INSTRUCTIONTOKEN_H

#include "IToken/IToken.h"
#include "eInstruction/eInstruction.h"

class InstructionToken : public IToken
{
public:
	InstructionToken();
	InstructionToken(const InstructionToken& src);
	~InstructionToken();
	InstructionToken& operator=(const InstructionToken& rhs);
	TokenType getType() const override;
	eInstruction getContent() const;
private:
};

#endif
