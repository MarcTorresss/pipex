/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:00:07 by martorre          #+#    #+#             */
/*   Updated: 2023/12/14 11:44:29 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	**paths;
	char	*cmd1;
	char	*cmd2;
	char	**com1;
	char	**com2;
	char	**envp;
	int		f1;
	int		f2;
	int		end[2];
	int		numchi;
	pid_t	child1;
	pid_t	child2;
}			t_pipex;

char	**ft_envpaths(char **env);
int     check_errors(void);
char	*check_path(char **paths, char **comand);
char	*check_path_ch(char **paths, char **comand);


#endif