#ifndef UNKNOWNINSTRUCTIONEXCEPTION_H
# define UNKNOWNINSTRUCTIONEXCEPTION_H

#include <exception>

class UnknownInstructionException : public std::exception
{
public:
    UnknownInstructionException() = default;
    UnknownInstructionException(const UnknownInstructionException & src) = default;
    ~UnknownInstructionException() = default;
    UnknownInstructionException& operator=(const UnknownInstructionException & rhs) = default;
    UnknownInstructionException(UnknownInstructionException&&) = default;
    UnknownInstructionException& operator=(UnknownInstructionException&&) = default;

    const char* what() const override;
private:
};

#endif
