/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:36:59 by lebronen          #+#    #+#             */
/*   Updated: 2023/09/01 14:48:51 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int    alloc(t_data *data)
{

    data->tid = malloc(data->philo_num * sizeof(pthread_t));
    if (!data->tid)
        return (error(ALLOC_ERR_1, data));
    data->philos = malloc(data->philo_num * sizeof(t_philo));
    if (!data->philos)
        return (error(ALLOC_ERR_2, data));
    data->forks = malloc(data->philo_num * sizeof(pthread_mutex_t));
    if (!data->forks)
        return (error(ALLOC_ERR_3, data));
    return (0);
}

int     data_init(t_data *data, int ac, char **av)
{
    data->philo_num = ft_atoi(av[0]);
    data->death_time = ft_atoi(av[1]);
    data->eat_time = ft_atoi(av[2]);
    data->sleep_time = ft_atoi(av[3]);
    if (ac == 5)
        data->meals_nb = ft_atoi(av[4]);
    else
        data->meals_nb = -1;
    if (data->philo_num <= 0 || data->philo_num > 200 || data->death_time < 0
        || data->eat_time < 0 || data->sleep_time < 0)
        return (error(ERR_IN_2, NULL));
    data->dead = 0;
    data->finished = 0;
    pthread_mutex_init(&data->write, NULL);
    pthread_mutex_init(&data->lock, NULL);
    return (0);
}

int     forks_init(t_data *data)
{
    int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	i = 1;
	while (i < data->philo_num)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

void    philos_init(t_data *data)
{
    int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_cont = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}   
}

int     init(t_data *data, int ac, char **av)
{
    if (data_init(data, ac, av))
        return (1);
    if (alloc(data))
        return (1);
    if (forks_init(data))
        return (1);
    philos_init(data);
    return (0);
}