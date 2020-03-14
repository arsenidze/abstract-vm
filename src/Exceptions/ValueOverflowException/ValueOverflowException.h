#ifndef VALUEOVERFLOWEXCEPTION_H
# define VALUEOVERFLOWEXCEPTION_H

#include <exception>
#include <stdexcept>

class ValueOverflowException : std::runtime_error
{
public:
    ValueOverflowException();
    ValueOverflowException(const ValueOverflowException & src) = default;
    ~ValueOverflowException() = default;
    ValueOverflowException& operator=(const ValueOverflowException & rhs) = default;
    ValueOverflowException(ValueOverflowException&&) = default;
    ValueOverflowException& operator=(ValueOverflowException&&) = default;

    const char* what() const override;
private:
};

#endif
