/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:00:07 by martorre          #+#    #+#             */
/*   Updated: 2023/12/18 14:53:41 by martorre         ###   ########.fr       */
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
	char	*cmd;
	char	*cmdp;
	char	*cmdexe;
	pid_t	child1;
	pid_t	child2;
}			t_pipex;

char		**ft_envpaths(char **env);
int			check_errors(void);
char		*check_path(t_pipex *stp, char **comand);
char		*check_path_ch(char **paths, char **comand);

#endif