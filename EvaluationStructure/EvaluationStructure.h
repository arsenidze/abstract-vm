#ifndef EVALUATIONSTRUCTURE_H
# define EVALUATIONSTRUCTURE_H

#include <memory>
#include <string>
#include "IAST/IAST.h"
#include "eInstruction/eInstruction.h"
#include "IOperand/IOperand.h"

struct EvaluationStructure : public IAST
{
public:
	EvaluationStructure();
	EvaluationStructure(eInstruction instruction, const IOperand * value, std::string comment);
//	EvaluationStructure(const EvaluationStructure& src);
//	~EvaluationStructure();
//	EvaluationStructure& operator=(const EvaluationStructure& rhs);
//private:
	eInstruction				instruction;
	const IOperand*					value;
	std::string					comment;

	bool isEmpty() const;
};

#endif
