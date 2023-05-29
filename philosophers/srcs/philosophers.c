/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:48:19 by rshay             #+#    #+#             */
/*   Updated: 2023/05/26 18:14:52 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include "../libft/libft.h"


int	main(int argc, char **argv)
{
	int			i;
	int			philo;
	int			nb;
	pthread_t	*thread_philo;

	if (argc >= 5 && argc <= 6)
	{
		i = 0;
		nb = ft_atoi(argv[1]);
		thread_philo = malloc(nb * sizeof(int));
		while (i < nb)
		{
			philo = pthread_create(&thread_philo[i], NULL, ft_philo, (void *)i);
			i++;
		}

		i = 0;
		while (i < nb)
		{
			pthread_join(thread_philo[i], NULL);
			i++;
		}
			
	}
	else // si le nombre d'arguments n'est pas bon, on display une erreur
		//error();
	return (0);
}

void	*ft_philo(void *data)
{
	int	x;

	x = (int) data;
	while (1)
	{
		usleep(1000000);
		printf("philosophe %d mange\n", x);
	}
	return NULL;
}