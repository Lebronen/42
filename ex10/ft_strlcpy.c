
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	x;

	x = 0;
	while (*src && x < size)
	{
		*dest = *src;
		dest ++;
		src ++;
		x ++;
	}
	*dest = '\0';
	return x;
}
