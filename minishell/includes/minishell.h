/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:33:32 by rshay             #+#    #+#             */
/*   Updated: 2023/06/19 16:50:50 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>

void    prompt(char **envp);
void    execute(char *commande, char **envp);
void	error(void);
char	*find_path(char *cmd, char **envp);
int     nb_str(char *s, char c);
void    ft_pipe(char *commande, char **envp);
void	process(char *commande, char **envp);

#endif