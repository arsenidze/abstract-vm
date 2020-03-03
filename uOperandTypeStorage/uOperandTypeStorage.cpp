#include <string>
#include "uOperandTypeStorage.h"

uOperandTypeStorage	uOperandTypeStorage::create(eOperandType interpretationType, std::string const& value)
{
    uOperandTypeStorage res;
    switch (interpretationType)
    {
    case Int8:
        res.i8 = static_cast<int8_t>(stoi(value));
        break;
    case Int16:
        res.i16 = static_cast<int16_t>(stoi(value));
        break;
    case Int32:
        res.i32 = static_cast<int32_t>(stoi(value));
        break;
    case Float:
        res.f = static_cast<float>(stof(value));
        break;
    case Double:
        res.d = static_cast<double>(stod(value));
        break;
    default:
        res.d = 0;
        break;
    }
    return res;
}

uOperandTypeStorage	uOperandTypeStorage::sum(uOperandTypeStorage op1, uOperandTypeStorage op2, eOperandType interpretationType)
{
    uOperandTypeStorage res;
    switch (interpretationType)
    {
    case Int8:
        res.i8 = op1.i8 + op2.i8;
        break;
    case Int16:
        res.i16 = op1.i16 + op2.i16;
        break;
    case Int32:
        res.i32 = op1.i32 + op2.i32;
        break;
    case Float:
        res.f = op1.f + op2.f;
        break;
    case Double:
        res.d = op1.d + op2.d;
        break;
    default:
        res.d = 0;
        break;
    }
    return res;
}

uOperandTypeStorage	uOperandTypeStorage::sub(uOperandTypeStorage op1, uOperandTypeStorage op2, eOperandType interpretationType)
{
    uOperandTypeStorage res;
    switch (interpretationType)
    {
    case Int8:
        res.i8 = op1.i8 - op2.i8;
        break;
    case Int16:
        res.i16 = op1.i16 - op2.i16;
        break;
    case Int32:
        res.i32 = op1.i32 - op2.i32;
        break;
    case Float:
        res.f = op1.f - op2.f;
        break;
    case Double:
        res.d = op1.d - op2.d;
        break;
    default:
        res.d = 0;
        break;
    }
    return res;
}

uOperandTypeStorage	uOperandTypeStorage::mul(uOperandTypeStorage op1, uOperandTypeStorage op2, eOperandType interpretationType)
{
    uOperandTypeStorage res;
    switch (interpretationType)
    {
    case Int8:
        res.i8 = op1.i8 * op2.i8;
        break;
    case Int16:
        res.i16 = op1.i16 * op2.i16;
        break;
    case Int32:
        res.i32 = op1.i32 * op2.i32;
        break;
    case Float:
        res.f = op1.f * op2.f;
        break;
    case Double:
        res.d = op1.d * op2.d;
        break;
    default:
        res.d = 0;
        break;
    }
    return res;
}

uOperandTypeStorage	uOperandTypeStorage::div(uOperandTypeStorage op1, uOperandTypeStorage op2, eOperandType interpretationType)
{
    uOperandTypeStorage res;
    switch (interpretationType)
    {
    case Int8:
        res.i8 = op1.i8 / op2.i8;
        break;
    case Int16:
        res.i16 = op1.i16 / op2.i16;
        break;
    case Int32:
        res.i32 = op1.i32 / op2.i32;
        break;
    case Float:
        res.f = op1.f / op2.f;
        break;
    case Double:
        res.d = op1.d / op2.d;
        break;
    default:
        res.d = 0;
        break;
    }
    return res;
}

uOperandTypeStorage	uOperandTypeStorage::mod(uOperandTypeStorage op1, uOperandTypeStorage op2, eOperandType interpretationType)
{
    uOperandTypeStorage res;
    switch (interpretationType)
    {
    case Int8:
        res.i8 = op1.i8 % op2.i8;
        break;
    case Int16:
        res.i16 = op1.i16 % op2.i16;
        break;
    case Int32:
        res.i32 = op1.i32 % op2.i32;
        break;
    case Float:
        res.f = (int)op1.f % (int)op2.f;
        break;
    case Double:
        res.d = (int)op1.d % (int)op2.d;
        break;
    default:
        res.d = 0;
        break;
    }
    return res;
}

std::string uOperandTypeStorage::toString(eOperandType interpretationType) const
{
    switch (interpretationType)
    {
    case Int8:
        return std::to_string(this->i8);
    case Int16:
        return std::to_string(this->i16);
    case Int32:
        return std::to_string(this->i32);
    case Float:
        return std::to_string(this->f);
    case Double:
        return std::to_string(this->d);
    default:
        return "";
    }
}
