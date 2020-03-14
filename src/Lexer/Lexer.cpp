#include "Lexer.h"

#include <regex>

#include "Exceptions/LexicalErrorException/LexicalErrorException.h"
#include "Exceptions/UnknownInstructionException/UnknownInstructionException.h"
#include "TokenFactory/TokenFactory.h"

const std::pair<std::regex, eTokenType> Lexer::tokenMap[] =
{
    {std::regex("^(push|pop|dump|assert|add|sub|mul|div|mod|print|exit|sort|sumall|dumpex)$"), eTokenType::Instruction},
    {std::regex("^(int8|int16|int32)\\([-]?[0-9]+\\)$"), eTokenType::Value},
    {std::regex("^(float|double)\\([-]?[0-9]+.[0-9]+\\)$"), eTokenType::Value},
    {std::regex("^;(.*)$"), eTokenType::Comment}
};

std::vector<std::shared_ptr<IToken>> Lexer::getTokens(const std::string& line) const
{
	if (line.empty())
	{
        throw LexicalErrorException();
	}
	
    std::vector<std::shared_ptr<IToken>> tokens;
    std::regex  re("^(\\w+)?([ ]{1}([\\w().-]+))?([ ]*(;.+))?$");
    std::smatch m;

    auto isMatch = std::regex_match(line, m, re);

    if (!isMatch)
    {
        throw LexicalErrorException(); //Unrecognized lexemes structure
    }
	
    auto instruction = m[1].str();
    auto value = m[3].str();
    auto comment = m[5];

    std::string lexemes[] = {instruction, value, comment};

	for (const auto& lexeme : lexemes)
	{
		if (!lexeme.empty())
		{
            auto token = this->mapLexemeToToken(lexeme);
            tokens.push_back(token);
		}
	}
	
    return tokens;
}

std::shared_ptr<IToken> Lexer::mapLexemeToToken(const std::string &word) const
{
    std::smatch m;

	for (const auto& t: Lexer::tokenMap)
    {
        auto isMatch = std::regex_match(word, m, t.first);

        if (isMatch)
        {
            return TokenFactory::createToken(t.second, word);
        }
    }

    throw LexicalErrorException(); // Unknown lexeme
}