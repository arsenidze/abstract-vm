#ifndef READER_H
# define READER_H

#include <string>
#include <fstream>

class Reader
{
public:
	Reader();
	Reader(const std::string fileName);
	Reader(const Reader& src);
	~Reader();
	Reader& operator=(const Reader& rhs);
	bool		open(std::string fileName);
	std::string getLine();
private:
	std::ifstream	file;
	std::string		line;
};

#endif
