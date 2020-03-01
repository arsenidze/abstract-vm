CommentToken::CommentToken()
{
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

TokenType CommentToken::getType() const
{
    return TokenType::Comment;
}