#ifndef COMMENTTOKEN_H
# define COMMENTTOKEN_H

#include <string>
#include "IToken/IToken.h"

class CommentToken : public IToken
{
public:
	CommentToken(const std::string& value);
	CommentToken(const CommentToken& src);
	~CommentToken();
	CommentToken& operator=(const CommentToken& rhs);
	eTokenType getType() const override;
	std::string getContent() const;
private:
	std::string strRepresentation;
	std::string content;
};

#endif
