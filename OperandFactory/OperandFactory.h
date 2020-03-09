#ifndef OPERANDFACTORY_H
# define OPERANDFACTORY_H

#include "IOperand/IOperand.h"
#include "eOperandType/eOperandType.h"

class OperandFactory
{
public:
	OperandFactory() = delete;
    OperandFactory(const OperandFactory& src) = delete;
    ~OperandFactory() = delete;
    OperandFactory& operator=(const OperandFactory& rhs) = delete;
    OperandFactory(OperandFactory&&) = delete;
    OperandFactory& operator=(OperandFactory&&) = delete;
	static IOperand const* createOperand(eOperandType type, std::string const& value);
private:
	static IOperand const* createInt8(std::string const& value);
	static IOperand const* createInt16(std::string const& value);
	static IOperand const* createInt32(std::string const& value);
	static IOperand const* createFloat(std::string const& value);
	static IOperand const* createDouble(std::string const& value);

	static constexpr IOperand const* (*functionMap[])(std::string const& value) =
	{
		&OperandFactory::createInt8,
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble
	};
};

#endif
