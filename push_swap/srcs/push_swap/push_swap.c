/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:11:59 by rshay             #+#    #+#             */
/*   Updated: 2023/04/22 15:16:55 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
