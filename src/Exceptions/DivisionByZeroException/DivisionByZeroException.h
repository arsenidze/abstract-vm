#ifndef DIVISIONBYZEROEXCEPTION_H
# define DIVISIONBYZEROEXCEPTION_H

#include <exception>

class DivisionByZeroException : public std::exception
{
public:
	DivisionByZeroException() = default;
    DivisionByZeroException(const DivisionByZeroException& src) = default;
    ~DivisionByZeroException() = default;
    DivisionByZeroException& operator=(const DivisionByZeroException & rhs) = default;
    DivisionByZeroException(DivisionByZeroException&&) = default;
    DivisionByZeroException& operator=(DivisionByZeroException&&) = default;
	
	const char * what() const override;
private:
};

#endif
