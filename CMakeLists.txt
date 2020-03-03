# CMakeList.txt : CMake project for abstract-vm, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("abstract-vm")

set(SRCS 
	abstract-vm.cpp
	CommentToken/CommentToken.cpp
	EvaluationStructure/EvaluationStructure.cpp
	Evaluator/Evaluator.cpp
	InstructionToken/InstructionToken.cpp
	Lexer/Lexer.cpp
	Operand/Operand.cpp
	OperandFactory/OperandFactory.cpp
	Parser/Parser.cpp
	Reader/Reader.cpp
	TokenFactory/TokenFactory.cpp
	uOperandTypeStorage/uOperandTypeStorage.cpp
	ValueToken/ValueToken.cpp
)

set(HEADERS
	abstract-vm.h
	CommentToken/CommentToken.h
	eInstruction/eInstruction.h
	eOperandType/eOperandType.h
	eTokenType/eTokenType.h
	EvaluationStructure/EvaluationStructure.h
	Evaluator/Evaluator.h
	IAST/IAST.h
	InstructionToken/InstructionToken.h
	IOperand/IOperand.h
	IterableStack/IterableStack.h
	IToken/IToken.h
	Lexer/Lexer.h
	Operand/Operand.h
	OperandFactory/OperandFactory.h
	Parser/Parser.h
	Reader/Reader.h
	TokenFactory/TokenFactory.h
	uOperandTypeStorage/uOperandTypeStorage.h
	ValueToken/ValueToken.h
)

# Add source to this project's executable.
add_executable (abstract-vm ${SRCS} ${HEADERS})
target_include_directories(abstract-vm PRIVATE ".")

# TODO: Add tests and install targets if needed.

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})