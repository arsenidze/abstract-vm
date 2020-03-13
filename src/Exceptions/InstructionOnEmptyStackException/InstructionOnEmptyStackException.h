#ifndef INSTRUCTIONONEMPTYSTACKEXCEPTION_H
# define INSTRUCTIONONEMPTYSTACKEXCEPTION_H

#include <exception>

class InstructionOnEmptyStackException : public std::exception
{
public:
    InstructionOnEmptyStackException() = default;
    InstructionOnEmptyStackException(const InstructionOnEmptyStackException & src) = default;
    ~InstructionOnEmptyStackException() = default;
    InstructionOnEmptyStackException& operator=(const InstructionOnEmptyStackException & rhs) = default;
    InstructionOnEmptyStackException(InstructionOnEmptyStackException&&) = default;
    InstructionOnEmptyStackException& operator=(InstructionOnEmptyStackException&&) = default;

    const char* what() const override;
private:
};

#endif
