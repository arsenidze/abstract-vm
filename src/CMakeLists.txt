# CMakeList.txt : CMake project for abstract-vm, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("abstract-vm")

set(SRCS 
	main.cpp
	Tokens/CommentToken/CommentToken.cpp
	EvaluationStructure/EvaluationStructure.cpp
	Evaluator/Evaluator.cpp
	Tokens/InstructionToken/InstructionToken.cpp
	Lexer/Lexer.cpp
	Operand/Operand.cpp
	OperandFactory/OperandFactory.cpp
	Parser/Parser.cpp
	Reader/Reader.cpp
	TokenFactory/TokenFactory.cpp
	Tokens/ValueToken/ValueToken.cpp
	Exceptions/DivisionByZeroException/DivisionByZeroException.cpp
	Exceptions/FalseAssertException/FalseAssertException.cpp
	Exceptions/InstructionOnEmptyStackException/InstructionOnEmptyStackException.cpp
	Exceptions/LexicalErrorException/LexicalErrorException.cpp
	Exceptions/ModuloByZeroException/ModuloByZeroException.cpp
	Exceptions/NoExitException/NoExitException.cpp
	Exceptions/NotEnoughOperandsException/NotEnoughOperandsException.cpp
	Exceptions/SyntaxErrorException/SyntaxErrorException.cpp
	Exceptions/UnknownInstructionException/UnknownInstructionException.cpp
	Exceptions/ValueOverflowException/ValueOverflowException.cpp
	Exceptions/ValueUnderflowException/ValueUnderflowException.cpp
	Exceptions/InvalidValueException/InvalidValueException.cpp
	Exceptions/InstructionsAfterExitException/InstructionsAfterExitException.cpp
	Util/Conversion/Conversion.cpp
)

set(HEADERS
	Tokens/CommentToken/CommentToken.h
	eInstruction/eInstruction.h
	eOperandType/eOperandType.h
	eTokenType/eTokenType.h
	EvaluationStructure/EvaluationStructure.h
	Evaluator/Evaluator.h
	IAST/IAST.h
	Tokens/InstructionToken/InstructionToken.h
	IOperand/IOperand.h
	IterableStack/IterableStack.hpp
	Tokens/IToken/IToken.h
	Lexer/Lexer.h
	Operand/Operand.h
	OperandFactory/OperandFactory.h
	Parser/Parser.h
	Reader/Reader.h
	TokenFactory/TokenFactory.h
	Tokens/ValueToken/ValueToken.h
	Exceptions/DivisionByZeroException/DivisionByZeroException.h
	Exceptions/FalseAssertException/FalseAssertException.h
	Exceptions/InstructionOnEmptyStackException/InstructionOnEmptyStackException.h
	Exceptions/LexicalErrorException/LexicalErrorException.h
	Exceptions/ModuloByZeroException/ModuloByZeroException.h
	Exceptions/NoExitException/NoExitException.h
	Exceptions/NotEnoughOperandsException/NotEnoughOperandsException.h
	Exceptions/SyntaxErrorException/SyntaxErrorException.h
	Exceptions/UnknownInstructionException/UnknownInstructionException.h
	Exceptions/ValueOverflowException/ValueOverflowException.h
	Exceptions/ValueUnderflowException/ValueUnderflowException.h
	Exceptions/InvalidValueException/InvalidValueException.h
	Exceptions/InstructionsAfterExitException/InstructionsAfterExitException.h
	Util/Conversion/Conversion.h
)

# Add source to this project's executable.
add_executable (abstract-vm ${SRCS} ${HEADERS})
target_include_directories(abstract-vm PRIVATE ".")

target_compile_features(abstract-vm PRIVATE cxx_std_17)

install(TARGETS abstract-vm DESTINATION bin)

# TODO: Add tests and install targets if needed.

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input1.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input2.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_library(libabstract_vm STATIC ${SRCS} ${HEADERS})

target_include_directories(libabstract_vm PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(libabstract_vm PRIVATE cxx_std_17)