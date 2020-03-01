#ifndef EVALUATOR_H
# define EVALUATOR_H

#include <memory>
#include "IAST/IAST.h"
#include "IterableStack/IterableStack.h"
#include "IOperand/IOperand.h"

class Evaluator
{
public:
	Evaluator();
	Evaluator(const Evaluator& src);
	~Evaluator();
	Evaluator& operator=(const Evaluator& rhs);
	void	evaluate(std::shared_ptr<IAST> ast);
	bool	getIsExit() const;
private:
	IterableStack<std::shared_ptr<IOperand>>	stack;
	bool	isExit;

	void	push(std::shared_ptr<IOperand> value);
	std::shared_ptr<IOperand>	pop();
	void	dump();
	void	assert(std::shared_ptr<IOperand> value);
	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();
	void	print();
	void	exit();
};

#endif
