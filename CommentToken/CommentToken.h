#ifndef COMMENTTOKEN_H
# define COMMENTTOKEN_H

#include "IToken/IToken.h"

class CommentToken : public IToken
{
public:
	CommentToken();
	CommentToken(const CommentToken& src);
	~CommentToken();
	CommentToken& operator=(const CommentToken& rhs);
	TokenType getType() const override;
	std::string getContent() const;
private:
};

#endif
