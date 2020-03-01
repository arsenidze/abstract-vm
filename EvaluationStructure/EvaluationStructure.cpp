#include "EvaluationStructure.h"
#include "EvaluationStructure.h"

EvaluationStructure::EvaluationStructure()
{
    this->instruction = eInstruction::None;
    this->value = nullptr;
    this->comment = "";
}

EvaluationStructure::EvaluationStructure(eInstruction instruction, std::shared_ptr<IOperand> value, std::string comment)
{
    this->instruction = instruction;
    this->value = std::move(value);
    this->comment = std::move(comment);
}

EvaluationStructure::EvaluationStructure(const EvaluationStructure& src)
{
	*this = src;
}

EvaluationStructure::~EvaluationStructure()
{
}

EvaluationStructure& EvaluationStructure::operator=(const EvaluationStructure& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

bool EvaluationStructure::isEmpty() const
{
    return ((this->instruction == eInstruction::None) && (this->value == nullptr) && (this->comment == ""));
}