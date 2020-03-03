#ifndef EVALUATOR_H
# define EVALUATOR_H

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
