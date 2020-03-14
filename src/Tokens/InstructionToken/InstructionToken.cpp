#include "InstructionToken.h"

InstructionToken::InstructionToken(const std::string& value)
{
    this->strRepresentation = value;
	if (value == "push")
	{
		this->content = eInstruction::Push;
	}
	else if (value == "pop")
	{
		this->content = eInstruction::Pop;
	}
	else if (value == "dump")
	{
		this->content = eInstruction::Dump;
	}
	else if (value == "assert")
	{
		this->content = eInstruction::Assert;
	}
	else if (value == "add")
	{
		this->content = eInstruction::Add;
	}
	else if (value == "sub")
	{
		this->content = eInstruction::Sub;
	}
	else if (value == "mul")
	{
		this->content = eInstruction::Mul;
	}
	else if (value == "div")
	{
		this->content = eInstruction::Div;
	}
	else if (value == "mod")
	{
		this->content = eInstruction::Mod;
	}
	else if (value == "print")
	{
		this->content = eInstruction::Print;
	}
	else if (value == "exit")
	{
		this->content = eInstruction::Exit;
	}
	else if (value == "sort")
	{
		this->content = eInstruction::Sort;
	}
	else if (value == "sumall")
	{
		this->content = eInstruction::Sumall;
	}
	else if (value == "dumpex")
	{
		this->content = eInstruction::Dumpex;
	}
	else
	{
		this->content = eInstruction::None;
	}

}

eTokenType InstructionToken::getType() const
{
    return eTokenType::Instruction;
}

eInstruction InstructionToken::getContent() const
{
	return this->content;
}
