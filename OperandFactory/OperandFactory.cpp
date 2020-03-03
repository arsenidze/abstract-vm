#include "OperandFactory.h"
#include "Operand/Operand.h"

OperandFactory::OperandFactory()
{
}

OperandFactory::OperandFactory(const OperandFactory& src)
{
	*this = src;
}

OperandFactory::~OperandFactory()
{
}

OperandFactory& OperandFactory::operator=(const OperandFactory& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

IOperand const* OperandFactory::createOperand(eOperandType type, std::string const& value)
{
    return OperandFactory::functionMap[type](value);
}

IOperand const* OperandFactory::createInt8(std::string const& value)
{
    return new Operand(eOperandType::Int8, value);
}

IOperand const* OperandFactory::createInt16(std::string const& value)
{
    return new Operand(eOperandType::Int16, value);
}

IOperand const* OperandFactory::createInt32(std::string const& value)
{
    return new Operand(eOperandType::Int32, value);
}

IOperand const* OperandFactory::createFloat(std::string const& value)
{
    return new Operand(eOperandType::Float, value);
}

IOperand const* OperandFactory::createDouble(std::string const& value)
{
    return new Operand(eOperandType::Double, value);
}