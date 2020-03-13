#ifndef NOEXITEXCEPTION_H
# define NOEXITEXCEPTION_H

#include <exception>

class NoExitException : public std::exception
{
public:
    NoExitException() = default;
    NoExitException(const NoExitException & src) = default;
    ~NoExitException() = default;
    NoExitException& operator=(const NoExitException & rhs) = default;
    NoExitException(NoExitException&&) = default;
    NoExitException& operator=(NoExitException&&) = default;

    const char* what() const override;
private:
};

#endif
