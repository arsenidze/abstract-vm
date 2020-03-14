#ifndef INSTRUCTIONSAFTEREXITEXCEPTION_H
# define INSTRUCTIONSAFTEREXITEXCEPTION_H

#include <exception>

class InstructionsAfterExitException : public std::exception
{
public:
    InstructionsAfterExitException() = default;
    InstructionsAfterExitException(const InstructionsAfterExitException& src) = default;
    ~InstructionsAfterExitException() = default;
    InstructionsAfterExitException& operator=(const InstructionsAfterExitException& rhs) = default;
    InstructionsAfterExitException(InstructionsAfterExitException&&) = default;
    InstructionsAfterExitException& operator=(InstructionsAfterExitException&&) = default;

    const char* what() const override;
private:
};

#endif
