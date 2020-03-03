#ifndef LEXER_H
# define LEXER_H

#include <vector>
#include <memory>
#include <utility>
#include <regex>
#include "IToken/IToken.h"

class Lexer
{
public:
	Lexer();
	Lexer(const Lexer& src);
	~Lexer();
	Lexer& operator=(const Lexer& rhs);
	std::vector<std::shared_ptr<IToken>> getTokens(std::string line) const;
private:
	std::shared_ptr<IToken> mapWordToToken(const std::string& word) const;
	bool	isOptimizationCheckSayStop(size_t numOfLexems, std::shared_ptr<IToken> lastToken) const;
	static const std::pair<std::regex, eTokenType> tokenMap[];

	static const size_t MAX_NUMBER_OF_TOKENS_IN_SENTECE;
};

#endif
