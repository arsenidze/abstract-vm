#include "Evaluator.h"

#include <iostream>

#include "EvaluationStructure/EvaluationStructure.h"
#include "Exceptions/FalseAssertException/FalseAssertException.h"
#include "Exceptions/InstructionOnEmptyStackException/InstructionOnEmptyStackException.h"
#include "Exceptions/NoExitException/NoExitException.h"
#include "Exceptions/NotEnoughOperandsException/NotEnoughOperandsException.h"
#include "Exceptions/UnknownInstructionException/UnknownInstructionException.h"
#include "Operand/Operand.h"

Evaluator::Evaluator()
	: isExit(false)
{
}

void Evaluator::evaluate(const std::shared_ptr<IAST>& ast)
{
	const auto evaluationStructure = std::static_pointer_cast<EvaluationStructure>(ast);

    switch (evaluationStructure->instruction)
    {
		case eInstruction::Push:
			this->push(evaluationStructure->value);
			break;
		case eInstruction::Pop:
			this->pop();
			break;
		case eInstruction::Dump:
			this->dump();
			break;
		case eInstruction::Assert:
			this->assert(evaluationStructure->value);
			break;
		case eInstruction::Add:
			this->add();
			break;
		case eInstruction::Sub:
			this->sub();
			break;
		case eInstruction::Mul:
			this->mul();
			break;
		case eInstruction::Div:
			this->div();
			break;
		case eInstruction::Mod:
			this->mod();
			break;
		case eInstruction::Print:
			this->print();
			break;
		case eInstruction::Exit:
			this->exit();
			break;
		case eInstruction::None:
			break;
		default:
			throw UnknownInstructionException();
    }
}

bool Evaluator::getIsExit() const
{
	return this->isExit;
}

void Evaluator::exitCheck() const
{
	if (!this->isExit)
	{
		throw NoExitException();
	}
}

void	Evaluator::push(const IOperand* value)
{
	this->stack.push(value);
}

const IOperand*	Evaluator::pop()
{
	if (this->stack.empty())
	{
		throw InstructionOnEmptyStackException();
	}
	const IOperand * t = this->stack.top();
	this->stack.pop();
	return t;
}

void	Evaluator::dump()
{
	for (auto it = this->stack.rbegin(); it != this->stack.rend(); ++it)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

void	Evaluator::assert(const IOperand* value)
{
	if (this->stack.top()->toString() != value->toString())
	{
		throw FalseAssertException();
	}
}

void    Evaluator::add()
{
	if (this->stack.size() < 2)
	{
		throw NotEnoughOperandsException();
	}

	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = *op2 + *op1;
	this->push(res);

	delete op1;
	delete op2;
}

void    Evaluator::sub()
{
	if (this->stack.size() < 2)
	{
		throw NotEnoughOperandsException();
	}

	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = *op2 - *op1;
	this->push(res);

	delete op1;
	delete op2;
}

void    Evaluator::mul()
{
	if (this->stack.size() < 2)
	{
		throw NotEnoughOperandsException();
	}

	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = *op2 * *op1;
	this->push(res);

	delete op1;
	delete op2;
}

void    Evaluator::div()
{
	if (this->stack.size() < 2)
	{
		throw NotEnoughOperandsException();
	}

	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = *op2 / *op1;
	this->push(res);

	delete op1;
	delete op2;
}

void    Evaluator::mod()
{
	if (this->stack.size() < 2)
	{
		throw NotEnoughOperandsException();
	}

	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = *op2 % *op1;
	this->push(res);

	delete op1;
	delete op2;
}

void	Evaluator::print()
{
	const auto t = this->stack.top();
	
	if (t->getType() != eOperandType::Int8)
	{
		throw FalseAssertException();
	}

	const auto int8Bit = static_cast<int8_t>(stoi(t->toString()));
	const auto c = static_cast<char>(int8Bit);
	
	std::cout << c << std::endl;
}

void	Evaluator::exit()
{
	this->isExit = true;
}