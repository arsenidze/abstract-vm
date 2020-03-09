#ifndef INVALIDVALUEEXCEPTION_H
# define INVALIDVALUEEXCEPTION_H

#include <exception>

class InvalidValueException : std::exception
{
public:
    InvalidValueException() = default;
    InvalidValueException(const InvalidValueException & src) = default;
    ~InvalidValueException() = default;
    InvalidValueException& operator=(const InvalidValueException & rhs) = default;
    InvalidValueException(InvalidValueException&&) = default;
    InvalidValueException& operator=(InvalidValueException&&) = default;

    const char* what() const override;
private:
};

#endif
