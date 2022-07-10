
void	ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	x;

	x = -1;
	while (src[x] && ++x < n)
	{
		dest[x] = src[x];
	}
		
	while (x < n)
	{
		dest[x] = '\0';
		x ++;
	}
	return (dest);
}
