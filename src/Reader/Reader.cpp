#include "Reader.h"

#include <iostream>
#include <filesystem>

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
        this->fileName = fileName;
	}
    else
    {
        const auto tmpFileName = std::tmpnam(nullptr);

        if (tmpFileName == nullptr)
        {
            return false;
        }
    	
        if (!this->writeStdInToFile(tmpFileName, this->STDIN_END_STRING))
        {
            return false;
        }
    	
        this->fileName = tmpFileName;
    }
	
    this->file.open(this->fileName, std::ifstream::in);
    return this->file.is_open();
}

bool Reader::getLine(std::string& line_in)
{
    if (this->isEOR)
    {
        return false;
    }

    if (!std::getline(this->file, this->line))
    {
        this->isEOR = true;
    	
    	if (this->inputType == eInputType::StandardInput)
    	{
	        try
	        {
                std::filesystem::remove(this->fileName);
	        }
	        catch (...)
	        {
	        }
    	}
    	
        return false;
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

bool Reader::writeStdInToFile(const std::string& fileName, const std::string& stopString) const
{
    std::ofstream f(fileName);
    std::string line;

    if (!f.is_open())
    {
        return false;
    }
	
    while (std::getline(std::cin, line))
    {
        if (line == stopString)
        {
            break;
        }
        f << line << std::endl;
    }

    return true;
}