/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:00:07 by martorre          #+#    #+#             */
/*   Updated: 2023/12/11 17:59:51 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
#include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	char        **paths;
	char        *cmd1;
    char        *cmd2;
    char        **com1;
    char        **com2;
    char        **envp;
    int         f1;
    int         f2;
    int         end[2];
    pid_t       parent;
}					t_pipex;


#endif