
#include "Reader.h"

Reader::Reader()
{

}

Reader::Reader(const std::string fileName)
{
    this->file.open(fileName, std::ifstream::in);
}

Reader::Reader(const Reader& src)
{
	*this = src;
}

Reader::~Reader()
{
    this->file.close();
}

Reader& Reader::operator=(const Reader& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

bool Reader::open(std::string fileName)
{
    this->file.open(fileName, std::ifstream::in);
    return this->file.is_open();
}

std::string Reader::getLine()
{
    if (!this->file)
    {
        return "";
    }
    if (!std::getline(this->file, this->line))
    {
        this->line = "";
    }

    return this->line;
}
