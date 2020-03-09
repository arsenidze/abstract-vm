#ifndef FALSEASSERTEXCEPTION_H
# define FALSEASSERTEXCEPTION_H

#include <exception>

class FalseAssertException : public std::exception
{
public:
    FalseAssertException() = default;
    FalseAssertException(const FalseAssertException & src) = default;
    ~FalseAssertException() = default;
    FalseAssertException& operator=(const FalseAssertException & rhs) = default;
    FalseAssertException(FalseAssertException&&) = default;
    FalseAssertException& operator=(FalseAssertException&&) = default;

    const char* what() const override;
private:
};

#endif
