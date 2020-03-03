#include <algorithm>
#include <cmath>
#include <limits>
#include "Operand.h"
#include "OperandFactory/OperandFactory.h"

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
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1 = this->operandTypeStorage;
    auto op2 = dynamic_cast<const Operand&>(rhs).operandTypeStorage;
    auto value = uOperandTypeStorage::sum(op1, op2, generalType).toString(generalType);

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator-(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1 = this->operandTypeStorage;
    auto op2 = dynamic_cast<const Operand&>(rhs).operandTypeStorage;
    auto value = uOperandTypeStorage::sub(op1, op2, generalType).toString(generalType);

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator*(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1 = this->operandTypeStorage;
    auto op2 = dynamic_cast<const Operand&>(rhs).operandTypeStorage;
    auto value = uOperandTypeStorage::mul(op1, op2, generalType).toString(generalType);

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator/(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1 = this->operandTypeStorage;
    auto op2 = dynamic_cast<const Operand&>(rhs).operandTypeStorage;
    auto value = uOperandTypeStorage::div(op1, op2, generalType).toString(generalType);

    return OperandFactory::createOperand(generalType, value);
}

IOperand const* Operand::operator%(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1 = this->operandTypeStorage;
    auto op2 = dynamic_cast<const Operand&>(rhs).operandTypeStorage;
    auto value = uOperandTypeStorage::mod(op1, op2, generalType).toString(generalType);

    return OperandFactory::createOperand(generalType, value);
}

std::string	const& Operand::toString(void) const
{
    return this->value;
}

bool Operand::isZero() const
{
    switch (this->type)
    {
    case eOperandType::Int8:
    case eOperandType::Int16:
    case eOperandType::Int32:
        return this->operandTypeStorage.i32 == 0;
    case eOperandType::Float:
    case eOperandType::Double:
        return std::abs(this->operandTypeStorage.d - (int)this->operandTypeStorage.d) < std::numeric_limits<double>::lowest();
    default:
        return false;
    }
}