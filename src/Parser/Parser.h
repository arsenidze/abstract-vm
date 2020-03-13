#ifndef PARSER_H
# define PARSER_H

#include <vector>
#include <memory>
#include "IAST/IAST.h"
#include "Tokens/IToken/IToken.h"

class Parser
{
public:
    Parser() = default;
    Parser(const Parser& src) = delete;
    ~Parser() = default;
    Parser& operator=(const Parser & rhs) = delete;
    Parser(Parser&&) = delete;
    Parser& operator=(Parser&&) = delete;
	
	std::shared_ptr<IAST>	parse(std::vector<std::shared_ptr<IToken>> tokens);
private:
	static const size_t MAX_NUMBER_OF_TOKENS_IN_SENTECE;
};

#endif
