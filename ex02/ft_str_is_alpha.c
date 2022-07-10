#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (*str < 'A' || (*str > 'Z' && *str < 'a') || *str > 'z')
		{
			return (0);
		}
		str ++;
	}
	return (1);
}

int main ()
{
	char *str = "Bonjour";
	printf("%d\n", ft_str_is_alpha(str));
	return 0;
}
