/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:19:24 by rshay             #+#    #+#             */
/*   Updated: 2023/09/06 01:19:28 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char const *argv[])
{
	int			error;
	t_params	params;
	t_philo		*philos;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (parse_params(argc, argv, &params))
		return (EXIT_FAILURE);
	philos = NULL;
	params.time_to_eat *= 1000;
	params.time_to_sleep *= 1000;
	params.time_to_die *= 1000;
	if (init_philos(&philos, &params))
		return (clear_nodes(&philos), EXIT_FAILURE);
	error = init_mutexes(philos, &params);
	if (!error)
		error |= init_threads(philos, &params);
	error |= destroy_mutexes(philos, &params);
	return (clear_nodes(&philos), error);
}
