# CMakeList.txt : CMake project for abstract-vm, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("abstract-vm")

set(SRCS 
	abstract-vm.cpp
	Reader/Reader.cpp
	Lexer/Lexer.cpp
	InstructionToken/InstructionToken.cpp
	ValueToken/ValueToken.cpp
	CommentToken/CommentToken.cpp
	Parser/Parser.cpp
	EvaluationStructure/EvaluationStructure.cpp
	OperandFactory/OperandFactory.cpp
)

set(HEADERS
	abstract-vm.h
	Reader/Reader.h
	Lexer/Lexer.h
	IToken/IToken.h
	InstructionToken/InstructionToken.h
	ValueToken/ValueToken.h
	CommentToken/CommentToken.h
	Parser/Parser.h
	eInstruction/eInstruction.h
	IOperand/IOperand.h
	EvaluationStructure/EvaluationStructure.h
	IterableStack/IterableStack.h
	eOperandType/eOperandType.h
	OperandFactory/OperandFactory.h
)

# Add source to this project's executable.
add_executable (abstract-vm ${SRCS} ${HEADERS})
target_include_directories(abstract-vm PRIVATE ".")

# TODO: Add tests and install targets if needed.

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})