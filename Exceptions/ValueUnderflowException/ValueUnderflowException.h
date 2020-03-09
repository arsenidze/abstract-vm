#ifndef VALUEUNDERFLOWEXCEPTION_H
# define VALUEUNDERFLOWEXCEPTION_H

#include <exception>

class ValueUnderflowException : std::exception
{
public:
    ValueUnderflowException() = default;
    ValueUnderflowException(const ValueUnderflowException & src) = default;
    ~ValueUnderflowException() = default;
    ValueUnderflowException& operator=(const ValueUnderflowException & rhs) = default;
    ValueUnderflowException(ValueUnderflowException&&) = default;
    ValueUnderflowException& operator=(ValueUnderflowException&&) = default;

    const char* what() const override;
private:
};

#endif
