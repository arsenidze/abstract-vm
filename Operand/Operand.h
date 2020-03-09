#ifndef OPERAND_H
# define OPERAND_H

#include <string>
#include "IOperand/IOperand.h"
#include "eOperandType/eOperandType.h"

class Operand : public IOperand
{
public:
	Operand(eOperandType type, std::string const& value);
	Operand() = delete;
	Operand(const Operand& src) = default;
	~Operand() = default;
	Operand& operator=(const Operand& rhs) = default;
	Operand(Operand&&) = default;
	Operand& operator=(Operand&&) = default;
	
	int	getPrecision(void) const override;
	eOperandType	getType(void) const override;
	IOperand const* operator+(IOperand const& rhs) const override;
	IOperand const* operator-(IOperand const& rhs) const override;
	IOperand const* operator*(IOperand const& rhs) const override;
	IOperand const* operator/(IOperand const& rhs) const override;
	IOperand const* operator%(IOperand const& rhs) const override;
	std::string	const& toString(void) const override;
private:
	eOperandType type;
	std::string value;
	bool isZero() const;

	template <typename T>
	T	safeIntegerSum(T op1, T op2) const;
	template <typename T>
	T	safeFractionSum(T op1, T op2) const;
	template <typename T>
	T	safeIntegerSub(T op1, T op2) const;
	template <typename T>
	T	safeFractionSub(T op1, T op2) const;
	template <typename T>
	T	safeIntegerMul(T op1, T op2) const;
	template <typename T>
	T	safeFractionMul(T op1, T op2) const;
	template <typename T>
	T	safeIntegerDiv(T op1, T op2) const;
	template <typename T>
	T	safeFractionDiv(T op1, T op2) const;
	template <typename T>
	T	safeIntegerMod(T op1, T op2) const;
	template <typename T>
	T	safeFractionMod(T op1, T op2) const;
	template <>
	float	safeFractionMod(float op1, float op2) const;
};

#endif
