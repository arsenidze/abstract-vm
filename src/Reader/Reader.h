#ifndef READER_H
# define READER_H

#include <string>
#include <fstream>

#include "eInputType/eInputType.h"

class Reader
{
public:
	Reader();
	Reader(const Reader& src) = delete;
	~Reader() = default;
	Reader& operator=(const Reader& rhs) = delete;
	Reader(Reader&&) = delete;
	Reader& operator=(Reader&&) = delete;
	
	bool		open(eInputType type, const std::string& fileName = "");
	bool		getLine(std::string& line_in);
	bool		isEndOfReading() const;
	eInputType	getInputType() const;
private:
	eInputType		inputType;
	std::ifstream	file;
	std::string		line;
	bool			isEOR{};
	static const	std::string STDIN_END_STRING;
};

#endif
