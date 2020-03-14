#ifndef EVALUATIONSTRUCTURE_H
# define EVALUATIONSTRUCTURE_H

#include <string>

#include "IAST/IAST.h"
#include "eInstruction/eInstruction.h"
#include "IOperand/IOperand.h"

struct EvaluationStructure : public IAST
{
	EvaluationStructure();
	EvaluationStructure(eInstruction instruction, const IOperand * value, std::string comment);
	bool operator ==(const EvaluationStructure& other) const;
	bool isEmpty() const;

	eInstruction				instruction;
	const IOperand*				value;
	std::string					comment;
};

#endif
