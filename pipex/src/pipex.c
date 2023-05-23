/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:31:18 by rshay             #+#    #+#             */
/*   Updated: 2023/05/23 15:43:48 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
    pid_t	pid;

	if (argc == 5)
	{
        if (pipe(fd) == -1)
            error();
        pid = fork();
        if (pid == -1)
            error();
        else if (pid == 0)
        {
            child_process(argv, envp, fd);
        }
        parent_process(argv, envp, fd);
        close(fd[0]);
        close(fd[1]);
        wait(NULL);
        wait(NULL);
        
	}
    else
    {
        perror("entrez le bon nombre d'arguments");
    }
	return (0);
}

void    child_process(char **argv, char **envp, int *fd)
{
    int infile = open(argv[1], O_RDONLY, 0777);
    if (infile < 0)
        error();
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(infile, STDIN_FILENO);
    execute(argv[2], envp);
}

void    parent_process(char **argv, char **envp, int *fd)
{
    int outfile = open(argv[4], O_WRONLY, O_TRUNC, O_CREAT, 0777);
    if (outfile == 0)
        error();
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    execute(argv[3], envp);
}
