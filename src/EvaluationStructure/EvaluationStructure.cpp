#include "EvaluationStructure.h"

EvaluationStructure::EvaluationStructure()
{
    this->instruction = eInstruction::None;
    this->value = nullptr;
    this->comment = "";
}

EvaluationStructure::EvaluationStructure(eInstruction instruction, const IOperand * value, std::string comment)
{
    this->instruction = instruction;
    this->value = value;
    this->comment = std::move(comment);
}

bool EvaluationStructure::isEmpty() const
{
    return ((this->instruction == eInstruction::None) && (this->value == nullptr) && (this->comment.empty()));
}