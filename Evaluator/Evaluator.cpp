#include <iostream>
#include "Evaluator.h"
#include "EvaluationStructure/EvaluationStructure.h"

Evaluator::Evaluator()
	: isExit(false)
{
}

Evaluator::Evaluator(const Evaluator& src)
{
	*this = src;
}

Evaluator::~Evaluator()
{
}

Evaluator& Evaluator::operator=(const Evaluator& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

void Evaluator::evaluate(std::shared_ptr<IAST> ast)
{
    auto evaluationStructure = std::static_pointer_cast<EvaluationStructure>(ast);

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
			break;
    }
}

bool Evaluator::getIsExit() const
{
	return this->isExit;
}

void	Evaluator::push(std::shared_ptr<IOperand> value)
{
	this->stack.push(value);
}

std::shared_ptr<IOperand>	Evaluator::pop()
{
	if (this->stack.empty())
	{
		throw std::exception();
	}
	return this->stack.pop();
}

void	Evaluator::dump()
{
	for (auto elem: this->stack)
	{
		std::cout << elem << std::endl;
	}
}

void	Evaluator::assert(std::shared_ptr<IOperand> value)
{
	// TODO: comparison in IOperand
	if (this->stack.top() != value)
	{
		throw std::exception();
	}
}

void	Evaluator::add()
{
	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = op2 + op1;
	this->push(res);
}

void	Evaluator::sub()
{
	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = op2 - op1;
	this->push(res);
}

void	Evaluator::mul()
{
	auto op1 = this->pop();
	auto op2 = this->pop();

	auto res = op2 * op1;
	this->push(res);
}

void	Evaluator::div()
{
	auto op1 = this->pop();
	auto op2 = this->pop();

	if (op1->isZero())
	{
		throw std::exception();
	}

	auto res = op2 / op1;
	this->push(res);
}

void	Evaluator::mod()
{
	auto op1 = this->pop();
	auto op2 = this->pop();

	if (op1->isZero())
	{
		throw std::exception();
	}

	auto res = op2 % op1;
	this->push(res);
}

void	Evaluator::print()
{

}

void	Evaluator::exit()
{
	this->isExit = true;
}