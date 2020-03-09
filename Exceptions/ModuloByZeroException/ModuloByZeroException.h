#ifndef MODULOBYZEROEXCEPTION_H
# define MODULOBYZEROEXCEPTION_H

#include <exception>

class ModuloByZeroException : public std::exception
{
public:
    ModuloByZeroException() = default;
    ModuloByZeroException(const ModuloByZeroException & src) = default;
    ~ModuloByZeroException() = default;
    ModuloByZeroException& operator=(const ModuloByZeroException & rhs) = default;
    ModuloByZeroException(ModuloByZeroException&&) = default;
    ModuloByZeroException& operator=(ModuloByZeroException&&) = default;

    const char* what() const override;
private:
};

#endif
