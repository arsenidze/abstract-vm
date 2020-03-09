#include "OperandFactory.h"

#include <stdexcept>

#include "Exceptions/InvalidValueException/InvalidValueException.h"
#include "Exceptions/ValueOverflowException/ValueOverflowException.h"
#include "Exceptions/ValueUnderflowException/ValueUnderflowException.h"
#include "Operand/Operand.h"

IOperand const* OperandFactory::createOperand(eOperandType type, std::string const& value)
{
    return OperandFactory::functionMap[type](value);
}

IOperand const* OperandFactory::createInt8(std::string const& value)
{
	try
	{
        auto t = std::stoi(value);
	}
	catch (std::out_of_range&)
	{
        throw ValueOverflowException();
	}
	catch (std::invalid_argument&)
	{
		throw InvalidValueException();
	}
	
    return new Operand(eOperandType::Int8, value);
}

IOperand const* OperandFactory::createInt16(std::string const& value)
{
	try
	{
		auto t = std::stoi(value);
	}
	catch (std::out_of_range&)
	{
		throw ValueOverflowException();
	}
	catch (std::invalid_argument&)
	{
		throw InvalidValueException();
	}
	
    return new Operand(eOperandType::Int16, value);
}

IOperand const* OperandFactory::createInt32(std::string const& value)
{
	try
	{
		auto t = std::stoi(value);
	}
	catch (std::out_of_range&)
	{
		throw ValueOverflowException();
	}
	catch (std::invalid_argument&)
	{
		throw InvalidValueException();
	}
	
    return new Operand(eOperandType::Int32, value);
}

IOperand const* OperandFactory::createFloat(std::string const& value)
{
	try
	{
		auto t = std::stof(value);
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
	
    return new Operand(eOperandType::Float, value);
}

IOperand const* OperandFactory::createDouble(std::string const& value)
{
	try
	{
		auto t = std::stod(value);
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
	
    return new Operand(eOperandType::Double, value);
}