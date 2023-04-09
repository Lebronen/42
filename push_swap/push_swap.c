/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:25:06 by lebronen          #+#    #+#             */
/*   Updated: 2023/04/09 22:36:03 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_swap	stack;
	char	**s;
	int		x;

	if (argc <= 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	s = argv + 1;
	x = argc;
	if (argc == 2)
	{
		s = ft_split(argv[1], ' ');
		x = ft_len(s);
	}
	if (!bien_forme(s, x, &stack))
		ft_printf("Error\n");
	else
		algo(&stack);
	free_tab(s);
	free(stack.a);
	free(stack.b);
	return (0);
}

int	bien_forme(char **a, int x, t_swap *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack->a = malloc(sizeof(int) * x);
	stack->b = malloc(x * sizeof(int));
	while (j < x)
	{
		stack->a[j] = 0;
		stack->b[j] = 0;
		j++;
	}
	stack->len_a = x;
	stack->len_b = 0;
	while (i < x)
	{
		if (!is_nbr(a[i]) || (unsigned)ft_atoi(a[i]) > 2147483647)
			return (0);
		if (in_tab(stack->a, ft_atoi(a[i])))
			return (0);
	(stack->a)[i] = ft_atoi(a[i]);
		i++;
	}
	return (1);
}

int	in_tab(int *t, int x)
{
	int	i;

	i = 0;
	while (t[i])
	{
		if (t[i] == x)
			return (1);
		i++;
	}
	return (0);
}

int	is_nbr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	aff_tab(int *t, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", t[i]);
		i++;
	}
	ft_printf("\n");
}
