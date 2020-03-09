#include "Reader.h"

#include <iostream>

const std::string Reader::STDIN_END_STRING = ";;";

Reader::Reader()
    : isEOR(false)
{

}

bool Reader::open(eInputType inputType = eInputType::StandardInput, const std::string& fileName)
{
    this->inputType = inputType;
	if (this->inputType == eInputType::File)
	{
        this->file.open(fileName, std::ifstream::in);
        return this->file.is_open();
	}
    return true;
}

bool Reader::getLine(std::string& line_in)
{
	if (this->isEOR)
	{
        return false;
	}
	
	switch (this->inputType)
    {
    case eInputType::File:
        if (!std::getline(this->file, this->line))
        {
            this->isEOR = true;
            return false;
        }
        break;
    case eInputType::StandardInput:
        if (!std::getline(std::cin, this->line))
        {
            this->isEOR = true;
            return false;
        }
        if (this->line == this->STDIN_END_STRING)
        {
            this->isEOR = true;
        }
        break;
	}

    line_in = this->line;
    return true;
}

bool Reader::isEndOfReading() const
{
    return this->isEOR;
}

eInputType Reader::getInputType() const
{
    return this->inputType;
}
