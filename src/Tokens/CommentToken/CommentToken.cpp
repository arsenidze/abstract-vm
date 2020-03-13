#include "CommentToken.h"

CommentToken::CommentToken(const std::string& value)
{
    this->strRepresentation = value;
    this->content = value;
}

eTokenType CommentToken::getType() const
{
    return eTokenType::Comment;
}

std::string CommentToken::getContent() const
{
    return this->content;
}
