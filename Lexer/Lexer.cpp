
#include <sstream>
#include <regex>
#include "Lexer.h"
#include "TokenFactory/TokenFactory.h"

const size_t Lexer::MAX_NUMBER_OF_TOKENS_IN_SENTECE = 3;

//static const std::pair<std::regex, TokenType> tokenMap[] = { {"pop", TokenType::Comment} };
const std::pair<std::regex, eTokenType> Lexer::tokenMap[] =
{
    {std::regex("^(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)$"), eTokenType::Instruction},
    {std::regex("^(int8|int16|int32)\\([-]?[0-9]+\\)$"), eTokenType::Value},
    {std::regex("^(float|double)\\([-]?[0-9]+.[0-9]+\\)$"), eTokenType::Value},
    {std::regex("^;(.*)$"), eTokenType::Comment}
    /*{std::regex("dump"), TokenType::Instruction},
    {std::regex("add"), TokenType::Instruction},
    {std::regex("sub"), TokenType::Instruction},
    {std::regex("mul"), TokenType::Instruction},
    {std::regex("div"), TokenType::Instruction},
    {std::regex("mod"), TokenType::Instruction},
    {std::regex("print"), TokenType::Instruction},
    {std::regex("exit"), TokenType::Instruction}*/
};


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
        if (word.empty())
        {
            break;
        }
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

std::shared_ptr<IToken> Lexer::mapWordToToken(const std::string &word) const
{
    //std::regex  re("^(pop|dump|add|sub|mul|div|mod|print)[ \t]*(;.*)?\$");
    std::smatch m;

    for (size_t i = 0; i < sizeof(this->tokenMap) / sizeof(this->tokenMap[0]); i++)
    {
        auto isMatch = std::regex_match(word, m, this->tokenMap[i].first);

        if (isMatch)
        {
            return TokenFactory::createToken(this->tokenMap[i].second, word);
        }
    }
    return nullptr;
}

bool Lexer::isOptimizationCheckSayStop(size_t numOfTokens, std::shared_ptr<IToken> lastToken) const
{
    if (numOfTokens > this->MAX_NUMBER_OF_TOKENS_IN_SENTECE &&
        lastToken->getType() != eTokenType::Comment)
    {
        return true;
    }
    return false;
}