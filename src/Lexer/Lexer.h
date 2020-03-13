#ifndef LEXER_H
# define LEXER_H

#include <memory>
#include <regex>
#include <utility>
#include <vector>

#include "Tokens/IToken/IToken.h"

class Lexer
{
public:
	Lexer() = default;
    Lexer(const Lexer& src) = delete;
    ~Lexer() = default;
    Lexer& operator=(const Lexer & rhs) = delete;
    Lexer(Lexer&&) = delete;
    Lexer& operator=(Lexer&&) = delete;
	
	std::vector<std::shared_ptr<IToken>> getTokens(const std::string& line) const;
private:
	std::shared_ptr<IToken> mapLexemeToToken(const std::string& word) const;
	static const std::pair<std::regex, eTokenType> tokenMap[];
};

#endif
