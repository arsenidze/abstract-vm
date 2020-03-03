#ifndef OPERAND_H
# define OPERAND_H

#include <string>
#include "IOperand/IOperand.h"
#include "eOperandType/eOperandType.h"
#include "uOperandTypeStorage/uOperandTypeStorage.h"

class Operand : public IOperand
{
public:
	Operand(eOperandType type, std::string const& value);
	Operand(const Operand& src);
	~Operand();
	Operand& operator=(const Operand& rhs);
	int	getPrecision(void) const override;
	eOperandType	getType(void) const override;
	IOperand const* operator+(IOperand const& rhs) const override;
	IOperand const* operator-(IOperand const& rhs) const override;
	IOperand const* operator*(IOperand const& rhs) const override;
	IOperand const* operator/(IOperand const& rhs) const override;
	IOperand const* operator%(IOperand const& rhs) const override;
	std::string	const& toString(void) const override;
	bool isZero() const;
private:
	eOperandType type;
	std::string value;
	uOperandTypeStorage	operandTypeStorage;
};

#endif