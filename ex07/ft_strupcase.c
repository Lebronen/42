
char	*ft_strupcase(char *str)
{
	char *s2 = str;
	while (*s2)
	{
		if (*s2 >= 'a' && *s2 <= 'z')
			*s2 -= 32;
		s2 ++;
	}
	return (str);
}
