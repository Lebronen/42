/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:26:55 by rshay             #+#    #+#             */
/*   Updated: 2023/03/21 17:08:01 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int	main(int argc, char **argv, char *const envp[])
{
	int fd = open(argv[1], O_RDONLY);
	int id = fork();
	printf("%d\n", id);
	char *buffer = malloc(4096);
	char *s = malloc(strlen(argv[2] + strlen(argv[1]) + 3));
	strcat(s, "< ");
	strcat(s, argv[1]);
	strcat(s, argv[2]);
	int rd = read(fd, buffer, 4096);
	char	*var;
	setenv("PATH", ".", 1);
	puts(s);
	execve(s, argv + 1, envp);
}
