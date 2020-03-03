#include "CommentToken.h"

CommentToken::CommentToken(const std::string& value)
{
    this->strRepresentation = value;
    this->content = value;
}

CommentToken::CommentToken(const CommentToken& src)
{
	*this = src;
}

CommentToken::~CommentToken()
{
}

CommentToken& CommentToken::operator=(const CommentToken& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

eTokenType CommentToken::getType() const
{
    return eTokenType::Comment;
}

std::string CommentToken::getContent() const
{
    return this->content;
}
