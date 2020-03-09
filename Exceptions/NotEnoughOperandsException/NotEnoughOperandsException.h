#ifndef NOTENOUGHOPERANDSEXCEPTION_H
# define NOTENOUGHOPERANDSEXCEPTION_H

#include <exception>

class NotEnoughOperandsException : public std::exception
{
public:
    NotEnoughOperandsException() = default;
    NotEnoughOperandsException(const NotEnoughOperandsException & src) = default;
    ~NotEnoughOperandsException() = default;
    NotEnoughOperandsException& operator=(const NotEnoughOperandsException & rhs) = default;
    NotEnoughOperandsException(NotEnoughOperandsException&&) = default;
    NotEnoughOperandsException& operator=(NotEnoughOperandsException&&) = default;

    const char* what() const override;
private:
};

#endif
