/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:52:54 by martorre          #+#    #+#             */
/*   Updated: 2023/12/13 19:42:38 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_envpaths(char **env)
{
	int		y;
	char	*path;
	char	**paths;

	y = 0;
	while (env[y] != NULL)
	{
		if (ft_strnstr(env[y], "PATH=", 5) != 0)
			path = ft_strnstr(env[y], "PATH=", 5);
		y++;
	}
	paths = ft_split(path, ':');
	paths[0] = ft_strchr(paths[0], '/');
	return (paths);
}

int	check_errors(void)
{
	if (errno == EACCES)
	{
		perror("Pipex");
		exit(127);
	}
	else if (errno == ENOENT)
	{
		perror("Command not found");
		exit(126);
	}
	exit(1);
}

char	*check_path(char **paths, char **comand)
{
	int		y;
	char	*cmd;

	y = 0;
	while (paths[y] != NULL)
	{
		cmd = ft_strjoin(paths[y], "/");
		if (!cmd)
			return (NULL);
		cmd = ft_strjoin(cmd, comand[0]);
		if (!cmd)
			return (NULL);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		y++;
	}
	return (NULL);
}
