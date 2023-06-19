/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:10:40 by rshay             #+#    #+#             */
/*   Updated: 2023/06/19 18:15:48 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int nb_str(char *s, char c)
{
    int i;

    i = 0;
    while (*s++)
    {
        if (c == *s)
            i++;
    }
    return (i);
}

void    child_process(char *commande, char **envp)
{
    pid_t	pid;
    int     status;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
    commande = ft_strtrim(commande, " ");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(commande, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, &status, 0);
	}
}

void    ft_pipe(char *commande, char **envp)
{
    char **list_commandes;
    int     i;

    list_commandes = ft_split(commande, '|');
    i = 0;
    while (i < nb_str(commande, '|'))
    {
        child_process(list_commandes[i], envp);
        i++;
    }
    execute(list_commandes[i], envp);
}