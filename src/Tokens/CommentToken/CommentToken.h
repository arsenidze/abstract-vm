#ifndef COMMENTTOKEN_H
# define COMMENTTOKEN_H

#include <string>
#include "Tokens/IToken/IToken.h"

class CommentToken : public IToken
{
public:
	CommentToken(const std::string& value);
	CommentToken() = delete;
	CommentToken(const CommentToken& src) = default;
	~CommentToken() = default;
	CommentToken& operator=(const CommentToken & rhs) = default;
	CommentToken(CommentToken&&) = default;
	CommentToken& operator=(CommentToken&&) = default;
	
	eTokenType getType() const override;
	std::string getContent() const;
private:
	std::string strRepresentation;
	std::string content;
};

#endif
