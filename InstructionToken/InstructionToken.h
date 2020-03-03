#ifndef INSTRUCTIONTOKEN_H
# define INSTRUCTIONTOKEN_H

#include <string>
#include "IToken/IToken.h"
#include "eInstruction/eInstruction.h"

class InstructionToken : public IToken
{
public:
	InstructionToken(const std::string &value);
	InstructionToken(const InstructionToken& src);
	~InstructionToken();
	InstructionToken& operator=(const InstructionToken& rhs);
	eTokenType getType() const override;
	eInstruction getContent() const;
private:
	std::string strRepresentation;
	eInstruction content;
};

#endif
