/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:22:01 by rshay             #+#    #+#             */
/*   Updated: 2023/09/06 01:22:04 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned long	t_ulong;

typedef struct s_params {
	bool			should_exit;
	pthread_mutex_t	exit;
	pthread_mutex_t	display;
	pthread_mutex_t	eat;
	pthread_mutex_t	sync;
	unsigned int	synced;
	t_ulong			start;
	unsigned int	philosophers;
	unsigned int	eat_enough;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_must_eat;
}				t_params;

typedef struct s_philo {
	struct s_philo	*prev;
	pthread_t		thread;
	pthread_mutex_t	prev_eat;
	pthread_mutex_t	fork;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	t_params		*params;
	t_ulong			last_eat;
	unsigned int	n;
	unsigned int	eats;
	struct s_philo	*next;
}				t_philo;

// Parser
bool	parse_params(int argc, char const *argv[], t_params *params);

// Initializer
bool	init_threads(t_philo *philos, t_params *params);
bool	init_philos(t_philo **philos, t_params *params);
bool	init_mutexes(t_philo *philos, t_params *params);

// Syncer
void	sync_thread(t_params *params);
void	set_start(t_philo *philos, t_params *params);

// Routines
void	*philo_routine(void *arg);
void	watcher(t_philo *philos, t_params *params);

// Utils
t_ulong	current_time_micros(void);
bool	check_stop(t_params *params);
bool	destroy_mutexes(t_philo *philos, t_params *params);
void	*philo_routine(void *philo);
void	clear_nodes(t_philo **philos);
void	print_state(t_philo *philo, char *action);
void	watcher(t_philo *philos, t_params *params);
void	ft_usleep(t_philo *philo, unsigned int micros);

#endif
