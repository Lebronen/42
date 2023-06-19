/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:42:53 by rshay             #+#    #+#             */
/*   Updated: 2023/06/19 18:07:12 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	is_slash(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
			return (1);
		i++;
	}
	return (0);
}


void    execute(char *commande, char **envp)
{
    char    **cmd;
    char    *path;
    int     i;
    
    
        cmd = ft_split(commande, ' ');
        if (is_slash(cmd[0]))
            path = cmd[0];
        else
            path = find_path(cmd[0], envp);
        if (!path || execve(path, cmd, envp) == -1)
	    {  
            i = -1;
            while (cmd[++i])
                free(cmd[i]);
            free(cmd);
            error();
		}
}

void	process(char *commande, char **envp)
{
	int		i;
	int		nb;
	pid_t   pid;
	int		status;

	i = 0;
	nb = nb_str(commande, '|');
	if (!nb)
	{
		pid = fork();
		if (pid == 0)
			execute(commande, envp);
		else if (pid > 0)
    	{
			waitpid(pid, &status, 0);
    	}
		else
			perror("fork");
	}
	else
		ft_pipe(commande, envp);
}