#ifndef SYNTAXERROREXCEPTION_H
# define SYNTAXERROREXCEPTION_H

#include <exception>

class SyntaxErrorException : public std::exception
{
public:
    SyntaxErrorException() = default;
    SyntaxErrorException(const SyntaxErrorException & src) = default;
    ~SyntaxErrorException() = default;
    SyntaxErrorException& operator=(const SyntaxErrorException & rhs) = default;
    SyntaxErrorException(SyntaxErrorException&&) = default;
    SyntaxErrorException& operator=(SyntaxErrorException&&) = default;

    const char* what() const override;
private:
};

#endif
