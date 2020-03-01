#ifndef PARSER_H
# define PARSER_H

#include <vector>
#include <memory>
#include "IAST/IAST.h"
#include "IToken/IToken.h"

class Parser
{
public:
	Parser();
	Parser(const Parser& src);
	~Parser();
	Parser& operator=(const Parser& rhs);
	std::shared_ptr<IAST>	parse(std::vector<std::shared_ptr<IToken>> tokens);
private:
	static const size_t MAX_NUMBER_OF_TOKENS_IN_SENTECE;
};

#endif
