#ifndef LEXICALERROREXCEPTION_H
# define LEXICALERROREXCEPTION_H

#include <exception>

class LexicalErrorException : public std::exception
{
public:
    LexicalErrorException() = default;
    LexicalErrorException(const LexicalErrorException & src) = default;
    ~LexicalErrorException() = default;
    LexicalErrorException& operator=(const LexicalErrorException & rhs) = default;
    LexicalErrorException(LexicalErrorException&&) = default;
    LexicalErrorException& operator=(LexicalErrorException&&) = default;

    const char* what() const override;
private:
};

#endif
