#include <algorithm>
#include "Operand.h"
#include "OperandFactory/OperandFactory.h"

Operand::Operand()
{
}

Operand::Operand(eOperandType type, std::string const& value)
{
    this->type = type;
    this->value = value;
    this->operandTypeStorage = uOperandTypeStorage::create(type, value);
}

Operand::Operand(const Operand& src)
{
    *this = src;
}

Operand::~Operand()
{
}

Operand& Operand::operator=(const Operand& rhs)
{
    if (this == &rhs)
        return (*this);
    // ADD CODE
    return (*this);
}

int	Operand::getPrecision(void) const
{
    return static_cast<int>(this->type);
}

eOperandType	Operand::getType(void) const
{
    return this->type;
}

IOperand const* Operand::operator+(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(static_cast<int>(this->getPrecision()), static_cast<int>(rhs.getPrecision())));

    auto op1 = this->getOperandTypeStorage();
    auto op2 = this->getOperandTypeStorage();
    auto value = uOperandTypeStorage::sum(op1, op2, generalType).toString();

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator-(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(static_cast<int>(this->getPrecision()), static_cast<int>(rhs.getPrecision())));

    auto op1 = this->getOperandTypeStorage();
    auto op2 = this->getOperandTypeStorage();
    auto value = uOperandTypeStorage::sub(op1, op2, generalType).toString();

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator*(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(static_cast<int>(this->getPrecision()), static_cast<int>(rhs.getPrecision())));

    auto op1 = this->getOperandTypeStorage();
    auto op2 = this->getOperandTypeStorage();
    auto value = uOperandTypeStorage::mul(op1, op2, generalType).toString();

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator/(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(static_cast<int>(this->getPrecision()), static_cast<int>(rhs.getPrecision())));

    auto op1 = this->getOperandTypeStorage();
    auto op2 = this->getOperandTypeStorage();
    auto value = uOperandTypeStorage::div(op1, op2, generalType).toString();

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator%(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(static_cast<int>(this->getPrecision()), static_cast<int>(rhs.getPrecision())));

    auto op1 = this->getOperandTypeStorage();
    auto op2 = this->getOperandTypeStorage();
    auto value = uOperandTypeStorage::mod(op1, op2, generalType).toString();

    return OperandFactory::createOperand(generalType, value);
}

std::string	const& Operand::toString(void) const
{
    return this->value;
}