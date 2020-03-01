#ifndef OPERANDFACTORY_H
# define OPERANDFACTORY_H

#include "IOperand/IOperand.h"
#include "eOperandType/eOperandType.h"

class OperandFactory
{
public:
	OperandFactory();
	OperandFactory(const OperandFactory& src);
	~OperandFactory();
	OperandFactory& operator=(const OperandFactory& rhs);
	static IOperand const* createOperand(eOperandType type, std::string const& value);
private:
	IOperand const* createInt8(std::string const& value) const;
	IOperand const* createInt16(std::string const& value) const;
	IOperand const* createInt32(std::string const& value) const;
	IOperand const* createFloat(std::string const& value) const;
	IOperand const* createDouble(std::string const& value) const;

	static constexpr IOperand const* (OperandFactory::*functionMap[5])(std::string const& value) const=
	{
		&OperandFactory::createInt8,
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble
	};
};

#endif
