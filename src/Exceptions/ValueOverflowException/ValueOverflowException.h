#ifndef VALUEOVERFLOWEXCEPTION_H
# define VALUEOVERFLOWEXCEPTION_H

#include <exception>

class ValueOverflowException : std::exception
{
public:
    ValueOverflowException() = default;
    ValueOverflowException(const ValueOverflowException & src) = default;
    ~ValueOverflowException() = default;
    ValueOverflowException& operator=(const ValueOverflowException & rhs) = default;
    ValueOverflowException(ValueOverflowException&&) = default;
    ValueOverflowException& operator=(ValueOverflowException&&) = default;

    const char* what() const override;
private:
};

#endif
