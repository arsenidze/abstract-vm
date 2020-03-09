#ifndef EVALUATOR_H
# define EVALUATOR_H

#include <memory>

#include "IAST/IAST.h"
#include "IOperand/IOperand.h"
#include "IterableStack/IterableStack.hpp"

class Evaluator
{
public:
	Evaluator();
	Evaluator(const Evaluator& src) = delete;
	~Evaluator() = default;
	Evaluator& operator=(const Evaluator& rhs) = delete;
	Evaluator(Evaluator&&) = delete;
	Evaluator& operator=(Evaluator&&) = delete;
	
	void	evaluate(const std::shared_ptr<IAST>& ast);
	bool	getIsExit() const;
	void	exitCheck() const;
private:
	IterableStack<const IOperand *>	stack;
	bool	isExit;

	void	push(const IOperand * value);
	const IOperand* pop();
	void	dump();
	void	assert(const IOperand* value);
	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();
	void	print();
	void	exit();
};

#endif
