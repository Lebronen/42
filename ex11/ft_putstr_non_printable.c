
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_to_hexa(int n)
{
	if (n < 10)
		return ('0' + n);

	return (n - 10 + 'a');
}

void	ft_put_hexa(char c)
{
	char	a;
	char	b;
	write(1, "\\", 1);
	a = ft_to_hexa(c/16);
	b = ft_to_hexa(c%16);
	ft_putchar(a);
	ft_putchar(b);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32)
			ft_putchar(*str);
		else
			ft_put_hexa(*str);
		str ++;
	}
}
