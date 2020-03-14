#include "Operand.h"

#include <algorithm>
#include <cfenv>
#include <cmath>
#include <limits>
#include <stdexcept>

#include "Exceptions/DivisionByZeroException/DivisionByZeroException.h"
#include "Exceptions/InvalidValueException/InvalidValueException.h"
#include "Exceptions/ModuloByZeroException/ModuloByZeroException.h"
#include "Exceptions/ValueOverflowException/ValueOverflowException.h"
#include "Exceptions/ValueUnderflowException/ValueUnderflowException.h"
#include "OperandFactory/OperandFactory.h"

Operand::Operand(eOperandType type, std::string const& value)
{
    this->type = type;
    this->value = value;
}


int Operand::getPrecision(void) const
{
    return static_cast<int>(this->type);
}

eOperandType    Operand::getType(void) const
{
    return this->type;
}

IOperand const* Operand::operator+(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1Str = this->value;
    auto op2Str = rhs.toString();

    std::string resStr;
    try
    {
        switch (generalType)
        {
        case Int8:
        {
            auto op1Int8 = static_cast<int8_t>(std::stoi(op1Str));
            auto op2Int8 = static_cast<int8_t>(std::stoi(op2Str));

            auto resInt8 = safeIntegerSum(op1Int8, op2Int8);
            resStr = std::to_string(resInt8);
        }
        break;
        case Int16:
        {
            auto op1Int16 = static_cast<int16_t>(std::stoi(op1Str));
            auto op2Int16 = static_cast<int16_t>(std::stoi(op2Str));

            auto resInt16 = safeIntegerSum(op1Int16, op2Int16);
            resStr = std::to_string(resInt16);
        }
        break;
        case Int32:
        {
            auto op1Int32 = static_cast<int32_t>(std::stoi(op1Str));
            auto op2Int32 = static_cast<int32_t>(std::stoi(op2Str));

            auto resInt32 = safeIntegerSum(op1Int32, op2Int32);
            resStr = std::to_string(resInt32);
        }
        break;
        case Float:
        {
            auto op1Float = static_cast<float>(std::stof(op1Str));
            auto op2Float = static_cast<float>(std::stof(op2Str));

            auto resFloat = safeFractionSum(op1Float, op2Float);
            resStr = std::to_string(resFloat);
        }
        break;
        case Double:
        {
            auto op1Double = static_cast<double>(std::stod(op1Str));
            auto op2Double = static_cast<double>(std::stod(op2Str));

            auto resDouble = safeFractionSum(op1Double, op2Double);
            resStr = std::to_string(resDouble);
        }
        break;
        default:
            throw std::logic_error("Unknown type of operand");
        }
    }
    catch (std::overflow_error&)
    {
        throw ValueOverflowException();
    }
    catch (std::underflow_error&)
    {
        throw ValueUnderflowException();
    }
    catch (std::out_of_range&)
    {
        throw ValueOverflowException();
    }
    catch (std::invalid_argument&)
    {
        throw InvalidValueException();
    }

    return OperandFactory::createOperand(generalType, resStr);
}

IOperand const* Operand::operator-(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1Str = this->value;
    auto op2Str = rhs.toString();

    std::string resStr;
    try
    {
        switch (generalType)
        {
        case Int8:
        {
            auto op1Int8 = static_cast<int8_t>(std::stoi(op1Str));
            auto op2Int8 = static_cast<int8_t>(std::stoi(op2Str));

            auto resInt8 = safeIntegerSub(op1Int8, op2Int8);
            resStr = std::to_string(resInt8);
        }
        break;
        case Int16:
        {
            auto op1Int16 = static_cast<int16_t>(std::stoi(op1Str));
            auto op2Int16 = static_cast<int16_t>(std::stoi(op2Str));

            auto resInt16 = safeIntegerSub(op1Int16, op2Int16);
            resStr = std::to_string(resInt16);
        }
        break;
        case Int32:
        {
            auto op1Int32 = static_cast<int32_t>(std::stoi(op1Str));
            auto op2Int32 = static_cast<int32_t>(std::stoi(op2Str));

            auto resInt32 = safeIntegerSub(op1Int32, op2Int32);
            resStr = std::to_string(resInt32);
        }
        break;
        case Float:
        {
            auto op1Float = static_cast<float>(std::stof(op1Str));
            auto op2Float = static_cast<float>(std::stof(op2Str));

            auto resFloat = safeFractionSub(op1Float, op2Float);
            resStr = std::to_string(resFloat);
        }
        break;
        case Double:
        {
            auto op1Double = static_cast<double>(std::stod(op1Str));
            auto op2Double = static_cast<double>(std::stod(op2Str));

            auto resDouble = safeFractionSub(op1Double, op2Double);
            resStr = std::to_string(resDouble);
        }
        break;
        default:
            throw std::logic_error("Unknown type of operand");
        }
    }
    catch (std::overflow_error&)
    {
        throw ValueOverflowException();
    }
    catch (std::underflow_error&)
    {
        throw ValueUnderflowException();
    }
    catch (std::out_of_range&)
    {
        throw ValueOverflowException();
    }
    catch (std::invalid_argument&)
    {
        throw InvalidValueException();
    }

    return OperandFactory::createOperand(generalType, resStr);
}

IOperand const* Operand::operator*(IOperand const& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1Str = this->value;
    auto op2Str = rhs.toString();

    std::string resStr;
    try
    {
        switch (generalType)
        {
        case Int8:
        {
            auto op1Int8 = static_cast<int8_t>(std::stoi(op1Str));
            auto op2Int8 = static_cast<int8_t>(std::stoi(op2Str));

            auto resInt8 = safeIntegerMul(op1Int8, op2Int8);
            resStr = std::to_string(resInt8);
        }
        break;
        case Int16:
        {
            auto op1Int16 = static_cast<int16_t>(std::stoi(op1Str));
            auto op2Int16 = static_cast<int16_t>(std::stoi(op2Str));

            auto resInt16 = safeIntegerMul(op1Int16, op2Int16);
            resStr = std::to_string(resInt16);
        }
        break;
        case Int32:
        {
            auto op1Int32 = static_cast<int32_t>(std::stoi(op1Str));
            auto op2Int32 = static_cast<int32_t>(std::stoi(op2Str));

            auto resInt32 = safeIntegerMul(op1Int32, op2Int32);
            resStr = std::to_string(resInt32);
        }
        break;
        case Float:
        {
            auto op1Float = static_cast<float>(std::stof(op1Str));
            auto op2Float = static_cast<float>(std::stof(op2Str));

            auto resFloat = safeFractionMul(op1Float, op2Float);
            resStr = std::to_string(resFloat);
        }
        break;
        case Double:
        {
            auto op1Double = static_cast<double>(std::stod(op1Str));
            auto op2Double = static_cast<double>(std::stod(op2Str));

            auto resDouble = safeFractionMul(op1Double, op2Double);
            resStr = std::to_string(resDouble);
        }
        break;
        default:
            throw std::logic_error("Unknown type of operand");
        }
    }
    catch (std::overflow_error&)
    {
        throw ValueOverflowException();
    }
    catch (std::underflow_error&)
    {
        throw ValueUnderflowException();
    }
    catch (std::out_of_range&)
    {
        throw ValueOverflowException();
    }
    catch (std::invalid_argument&)
    {
        throw InvalidValueException();
    }

    return OperandFactory::createOperand(generalType, resStr);
}

IOperand const* Operand::operator/(IOperand const& rhs) const
{
    if (dynamic_cast<const Operand&>(rhs).isZero())
    {
        throw DivisionByZeroException();
    }

    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1Str = this->value;
    auto op2Str = rhs.toString();

    std::string resStr;
    try
    {
        switch (generalType)
        {
        case Int8:
        {
            auto op1Int8 = static_cast<int8_t>(std::stoi(op1Str));
            auto op2Int8 = static_cast<int8_t>(std::stoi(op2Str));

            auto resInt8 = safeIntegerDiv(op1Int8, op2Int8);
            resStr = std::to_string(resInt8);
        }
        break;
        case Int16:
        {
            auto op1Int16 = static_cast<int16_t>(std::stoi(op1Str));
            auto op2Int16 = static_cast<int16_t>(std::stoi(op2Str));

            auto resInt16 = safeIntegerDiv(op1Int16, op2Int16);
            resStr = std::to_string(resInt16);
        }
        break;
        case Int32:
        {
            auto op1Int32 = static_cast<int32_t>(std::stoi(op1Str));
            auto op2Int32 = static_cast<int32_t>(std::stoi(op2Str));

            auto resInt32 = safeIntegerDiv(op1Int32, op2Int32);
            resStr = std::to_string(resInt32);
        }
        break;
        case Float:
        {
            auto op1Float = static_cast<float>(std::stof(op1Str));
            auto op2Float = static_cast<float>(std::stof(op2Str));

            auto resFloat = safeFractionDiv(op1Float, op2Float);
            resStr = std::to_string(resFloat);
        }
        break;
        case Double:
        {
            auto op1Double = static_cast<double>(std::stod(op1Str));
            auto op2Double = static_cast<double>(std::stod(op2Str));

            auto resDouble = safeFractionDiv(op1Double, op2Double);
            resStr = std::to_string(resDouble);
        }
        break;
        default:
            throw std::logic_error("Unknown type of operand");
        }
    }
    catch (std::overflow_error&)
    {
        throw ValueOverflowException();
    }
    catch (std::underflow_error&)
    {
        throw ValueUnderflowException();
    }
    catch (std::out_of_range&)
    {
        throw ValueOverflowException();
    }
    catch (std::invalid_argument&)
    {
        throw InvalidValueException();
    }

    return OperandFactory::createOperand(generalType, resStr);
}
IOperand const* Operand::operator%(IOperand const& rhs) const
{
    if (dynamic_cast<const Operand&>(rhs).isZero())
    {
        throw ModuloByZeroException();
    }

    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1Str = this->value;
    auto op2Str = rhs.toString();

    std::string resStr;
    try
    {
        switch (generalType)
        {
        case Int8:
        {
            auto op1Int8 = static_cast<int8_t>(std::stoi(op1Str));
            auto op2Int8 = static_cast<int8_t>(std::stoi(op2Str));

            auto resInt8 = safeIntegerMod(op1Int8, op2Int8);
            resStr = std::to_string(resInt8);
        }
        break;
        case Int16:
        {
            auto op1Int16 = static_cast<int16_t>(std::stoi(op1Str));
            auto op2Int16 = static_cast<int16_t>(std::stoi(op2Str));

            auto resInt16 = safeIntegerMod(op1Int16, op2Int16);
            resStr = std::to_string(resInt16);
        }
        break;
        case Int32:
        {
            auto op1Int32 = static_cast<int32_t>(std::stoi(op1Str));
            auto op2Int32 = static_cast<int32_t>(std::stoi(op2Str));

            auto resInt32 = safeIntegerMod(op1Int32, op2Int32);
            resStr = std::to_string(resInt32);
        }
        break;
        case Float:
        {
            auto op1Float = static_cast<float>(std::stof(op1Str));
            auto op2Float = static_cast<float>(std::stof(op2Str));

            auto resFloat = safeFractionMod(op1Float, op2Float);
            resStr = std::to_string(resFloat);
        }
        break;
        case Double:
        {
            auto op1Double = static_cast<double>(std::stod(op1Str));
            auto op2Double = static_cast<double>(std::stod(op2Str));

            auto resDouble = safeFractionMod(op1Double, op2Double);
            resStr = std::to_string(resDouble);
        }
        break;
        default:
            throw std::logic_error("Unknown type of operand");
        }
    }
    catch (std::overflow_error&)
    {
        throw ValueOverflowException();
    }
    catch (std::underflow_error&)
    {
        throw ValueUnderflowException();
    }
    catch (std::out_of_range&)
    {
        throw ValueOverflowException();
    }
    catch (std::invalid_argument&)
    {
        throw InvalidValueException();
    }

    return OperandFactory::createOperand(generalType, resStr);
}

std::string const& Operand::toString(void) const
{
    return this->value;
}

bool Operand::operator==(const Operand& rhs) const
{
    return ((this->getType() == rhs.getType()) &&
        (this->toString() == rhs.toString()));
}

bool Operand::operator==(const IOperand& rhs) const
{
    auto t = dynamic_cast<const Operand&>(rhs);

    return Operand::operator==(t);
}

bool Operand::operator<(const Operand& rhs) const
{
    eOperandType generalType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

    auto op1Str = this->value;
    auto op2Str = rhs.toString();

    bool res;
    try
    {
        switch (generalType)
        {
        case Int8:
        {
            auto op1Int8 = static_cast<int8_t>(std::stoi(op1Str));
            auto op2Int8 = static_cast<int8_t>(std::stoi(op2Str));

            res = op1Int8 < op2Int8;
        }
        break;
        case Int16:
        {
            auto op1Int16 = static_cast<int16_t>(std::stoi(op1Str));
            auto op2Int16 = static_cast<int16_t>(std::stoi(op2Str));

            res = op1Int16 < op2Int16;
        }
        break;
        case Int32:
        {
            auto op1Int32 = static_cast<int32_t>(std::stoi(op1Str));
            auto op2Int32 = static_cast<int32_t>(std::stoi(op2Str));

            res = op1Int32 < op2Int32;
        }
        break;
        case Float:
        {
            auto op1Float = static_cast<float>(std::stof(op1Str));
            auto op2Float = static_cast<float>(std::stof(op2Str));

            res = op1Float < op2Float;
        }
        break;
        case Double:
        {
            auto op1Double = static_cast<double>(std::stod(op1Str));
            auto op2Double = static_cast<double>(std::stod(op2Str));

            res = op1Double < op2Double;
        }
        break;
        default:
            throw std::logic_error("Unknown type of operand");
        }
    }
    catch (std::overflow_error&)
    {
        throw ValueOverflowException();
    }
    catch (std::underflow_error&)
    {
        throw ValueUnderflowException();
    }
    catch (std::out_of_range&)
    {
        throw ValueOverflowException();
    }
    catch (std::invalid_argument&)
    {
        throw InvalidValueException();
    }

    return res;
}

bool Operand::operator<(const IOperand& rhs) const
{
    auto t = dynamic_cast<const Operand&>(rhs);

    return Operand::operator<(t);
}

bool Operand::isZero() const
{
    int32_t i;
    float   f;
    double  d;
    switch (this->type)
    {
    case eOperandType::Int8:
    case eOperandType::Int16:
    case eOperandType::Int32:
        i = static_cast<int32_t>(std::stoi(this->value));
        return i == 0;
    case eOperandType::Float:
        f = static_cast<float>(std::stof(this->value));
        return std::abs(f - static_cast<int>(f)) < std::numeric_limits<float>::min();
    case eOperandType::Double:
        d = static_cast<double>(std::stod(this->value));
        return std::abs(d - static_cast<int>(d)) < std::numeric_limits<double>::min();
    default:
        throw std::logic_error("Unknown type of operand");
    }
}

template <typename  T>
T Operand::safeIntegerSum(T op1, T op2) const
{
    if (op1 > 0 && op2 > 0 && op1 > std::numeric_limits< T >::max() - op2)
        throw ValueOverflowException();

    if (op1 < 0 && op2 < 0 && op1 < std::numeric_limits< T >::min() - op2)
        throw ValueOverflowException();

    T res = op1 + op2;

    return res;
}

template <typename T>
T Operand::safeFractionSum(T op1, T op2) const
{
    std::feclearexcept(FE_ALL_EXCEPT);

    T res = op1 + op2;

    if (fetestexcept(FE_OVERFLOW))
    {
        throw ValueOverflowException();
    }
    if (fetestexcept(FE_UNDERFLOW))
    {
        throw ValueUnderflowException();
    }

    return  res;
}

template <typename T>
T Operand::safeIntegerSub(T op1, T op2) const
{
    if (op1 > 0 && op2 < 0 && op1 > std::numeric_limits< T >::max() - op2)
        throw ValueOverflowException();

    if (op1 < 0 && op2 > 0 && op1 < std::numeric_limits< T >::min() - op2)
        throw ValueOverflowException();

    T res = op1 - op2;

    return res;
}

template <typename T>
T Operand::safeFractionSub(T op1, T op2) const
{
    std::feclearexcept(FE_ALL_EXCEPT);

    T res = op1 - op2;

    if (fetestexcept(FE_OVERFLOW))
    {
        throw ValueOverflowException();
    }
    if (fetestexcept(FE_UNDERFLOW))
    {
        throw ValueUnderflowException();
    }

    return  res;
}

template <typename T>
T Operand::safeIntegerMul(T op1, T op2) const
{
    int64_t res = op1 * op2;

    if (res > std::numeric_limits<T>::max())
    {
        throw ValueOverflowException();
    }
    if (res < std::numeric_limits<T>::min())
    {
        throw ValueOverflowException();
    }

    return static_cast<T>(res);
}

template <typename T>
T Operand::safeFractionMul(T op1, T op2) const
{
    std::feclearexcept(FE_ALL_EXCEPT);

    T res = op1 * op2;

    if (fetestexcept(FE_OVERFLOW))
    {
        throw ValueOverflowException();
    }
    if (fetestexcept(FE_UNDERFLOW))
    {
        throw ValueUnderflowException();
    }

    return  res;
}

template <typename T>
T Operand::safeIntegerDiv(T op1, T op2) const
{
    T res;

    res = op1 / op2;
    return res;
}

template <typename T>
T Operand::safeFractionDiv(T op1, T op2) const
{
    std::feclearexcept(FE_ALL_EXCEPT);

    T res = op1 / op2;

    if (fetestexcept(FE_OVERFLOW))
    {
        throw ValueOverflowException();
    }
    if (fetestexcept(FE_UNDERFLOW))
    {
        throw ValueUnderflowException();
    }

	// Additional check on div by zero
    if (fetestexcept(FE_DIVBYZERO))
    {
        throw DivisionByZeroException();
    }

    return  res;
}

template <typename T>
T Operand::safeIntegerMod(T op1, T op2) const
{
    T res;

    res = op1 % op2;
    return res;
}

template <typename T>
T Operand::safeFractionMod(T op1, T op2) const
{
    std::feclearexcept(FE_ALL_EXCEPT);

    T res = fmod(static_cast<double>(op1), static_cast<double>(op2));

    if (fetestexcept(FE_OVERFLOW))
    {
        throw ValueOverflowException();
    }
    if (fetestexcept(FE_UNDERFLOW))
    {
        throw ValueUnderflowException();
    }

    return  res;
}

template <>
float Operand::safeFractionMod(float op1, float op2) const
{
    std::feclearexcept(FE_ALL_EXCEPT);

    float res = fmodf(op1, op2);

    if (fetestexcept(FE_OVERFLOW))
    {
        throw ValueOverflowException();
    }
    if (fetestexcept(FE_UNDERFLOW))
    {
        throw ValueUnderflowException();
    }

    return  res;
}