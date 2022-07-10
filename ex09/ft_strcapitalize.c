
int	ft_char_is_alpha(char c)
{
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}

int	ft_char_is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_char_is_alphanumeric(char c)
{
	return (ft_char_is_alpha(c) || ft_char_is_numeric(c));
}

char	ft_char_capitalize(char c)
{
	 if (c >= 'a' && c <= 'z')
		 return (c - 32);
	 return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	c;
	char	*s;

	c = 1;
	s = str;
	while (*s)
	{
		if (c && ft_char_is_alphanumeric(*s))
		{
			*s = ft_char_capitalize(*s);
			c = 0;
		}
		else if (!ft_char_is_alphanumeric(*s))
			c = 1;
		s ++;
	}
	return (str);
}
