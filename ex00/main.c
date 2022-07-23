#include <stdio.h>
#include "ft_larousse.h"
t_larousse *ft_dico(char **k, char **v, int size);
void	print_list(t_larousse *dict, int size);

int	main(void)
{
	char	*keys[5] = {"0", "1", "2", "3", "4"};
	char	*values[5] = {"zero", "un", "deux", "trois", "quatre"};
	t_larousse	*tab = ft_dico(keys, values, 5);
	print_list(*tab, 5);
	return (0);
}
