InstructionToken::InstructionToken()
{
}

InstructionToken::InstructionToken(const InstructionToken& src)
{
	*this = src;
}

InstructionToken::~InstructionToken()
{
}

InstructionToken& InstructionToken::operator=(const InstructionToken& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

TokenType InstructionToken::getType() const
{
    return TokenType::Instruction;
}