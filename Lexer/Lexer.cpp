
#include <sstream>
#include <regex>
#include "Lexer.h"

const size_t Lexer::MAX_NUMBER_OF_TOKENS_IN_SENTECE = 3;

Lexer::Lexer()
{
}

Lexer::Lexer(const Lexer& src)
{
	*this = src;
}

Lexer::~Lexer()
{
}

Lexer& Lexer::operator=(const Lexer& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

std::vector<std::shared_ptr<IToken>> Lexer::getTokens(std::string line) const
{
    std::vector<std::shared_ptr<IToken>> tokens;
    std::istringstream ss(line);
    size_t numOfTokens = 0;

    while (ss)
    {
        std::string word;
        ss >> word;
        auto token = this->mapWordToToken(word);
        numOfTokens++;

        if (this->isOptimizationCheckSayStop(numOfTokens, token))
        {
            throw std::exception();
        }
        tokens.push_back(token);
    }
    return tokens;
}

std::shared_ptr<IToken> Lexer::mapWordToToken(std::string word) const
{
    return std::shared_ptr<IToken>();
    std::regex  re("^(pop|dump|add|sub|mul|div|mod|print)[ \t]*(;.*)?\$");
    std::cmatch m;

    auto res = std::regex_match(line, m, re);

    for (auto it = this->tokenMap.begin(); it != this->tokenMap.end(); ++it)
    {
        std::regex_match(word, m, (*it).first)
    }
    
}

bool Lexer::isOptimizationCheckSayStop(size_t numOfTokens, std::shared_ptr<IToken> lastToken) const
{
    if (numOfTokens > this->MAX_NUMBER_OF_TOKENS_IN_SENTECE&&
        lastToken->getType() != TokenType::Comment)
    {
        return true;
    }
    return false;
}