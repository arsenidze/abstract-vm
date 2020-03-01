ValueToken::ValueToken()
{
}

ValueToken::ValueToken(const ValueToken& src)
{
	*this = src;
}

ValueToken::~ValueToken()
{
}

ValueToken& ValueToken::operator=(const ValueToken& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}

TokenType ValueToken::getType() const
{

}
