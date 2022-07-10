
int	ft_str_is_printable(char *c)
{
	while (*str)
	{
		if (*str < 32)
			return (0);
		str ++;
	}
	return (1);
}
