/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:13:28 by rshay             #+#    #+#             */
/*   Updated: 2023/05/22 17:19:56 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/include/libft.h"

void    error()
{
    perror("Erreur : ");
    exit(0);
}


char    *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    int     i;
    char    *part_path;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
    {
        i++;
    }
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
    {
        free(paths[i]);
    }
    free(paths);
    return (0);
}

void    execute(char *argv, char **envp)
{
    char    **cmd;
    char    *path;
    int i;
    
    cmd = ft_split(argv, ' ');
    path = find_path(cmd[0], envp);
    if (!path)
    {
        i = -1;
        while (cmd[++i])
        {
            free(cmd[i]);
        }
        free(cmd);
        error();
    }
    if (execve(path, cmd, envp))
        error();
}