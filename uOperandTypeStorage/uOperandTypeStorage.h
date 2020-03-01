#ifndef UOPERANDTYPESTORAGE_H
# define UOPERANDTYPESTORAGE_H

#include <cstdint>
#include <string>
#include "eOperandType/eOperandType.h"

union uOperandTypeStorage
{
	int8_t	i8;
	int16_t	i16;
	int32_t	i32;
	float	f;
	double	d;

	static uOperandTypeStorage	create(eOperandType interpretationType, std::string const& value);
	static uOperandTypeStorage	sum(uOperandTypeStorage op1, uOperandTypeStorage op2, eOperandType interpretationType);
	std::string	toString(eOperandType interpretationType) const;

};

#endif
