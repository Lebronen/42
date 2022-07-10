
char	ft_strlowcase(char *str)
{
	char *str2;

	str2 = str;
	while (*str2)
	{
		if (*str2 >= 'A' && *str2 <= 'Z')
			*str2 += 32;
		str2 ++;
	}
	return (str);
}
