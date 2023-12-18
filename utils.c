/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:52:54 by martorre          #+#    #+#             */
/*   Updated: 2023/12/18 14:31:42 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_envpaths(char **env)
{
	int		y;
	char	*path;
	char	**paths;

	paths = NULL;
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
		exit(126);
	}
	else if (errno == ENOENT)
	{
		perror("Command not foundC");
		exit(127);
	}
	exit(1);
}
/*char	*check_ut(int *exist, int *perm, char **paths, char **comand)
{
	int		y;
	char	*cmd;
	char	*cmdp;

	y = -1;
	while (paths[++y] != NULL)
	{
		cmdp = ft_strjoin(paths[y], "/");
		if (!cmdp)
			return (NULL);
		cmd = ft_strjoin(cmdp, comand[0]);
		free (cmdp);
		if (!cmd)
			return (NULL);
		if (access(cmd, F_OK) == 0)
		{
			(*exist) = 1;
			if (access(cmd, X_OK) == 0)
			{
				(*perm) = 1;
				return (NULL);
			}
			else
				free (cmd);
		}
	}
	return (cmd);
}

char	*check_path(char **paths, char **comand)
{
	int		exist;
	int		perm;
	char	*cmd;

	exist = 0;
	perm = 0;
	cmd = check_ut(&exist, &perm, paths, comand);
	if (exist == 0)
	{
		perror("Command not foundB");
		exit (127);
	}
	if (perm == 1)
		return (cmd);
	else
	{
		perror("Permission denied");
		exit (126);
	}
	return (NULL);
}*/

char	*check_path(char **paths, char **comand)
{
	int		y;
	char	*cmd;
	char	*cmdp;
	int		exist;
	int		perm;

	y = 0;
	exist = 0;
	perm = 0;
	while (paths[y] != NULL)
	{
		cmdp = ft_strjoin(paths[y], "/");
		if (!cmdp)
			return (NULL);
		cmd = ft_strjoin(cmdp, comand[0]);
		free (cmdp);
		if (!cmd)
			return (NULL);
		if (access(cmd, F_OK) == 0)
		{
			exist = 1;
			if (access(cmd, X_OK) == 0)
			{
				perm = 1;
				break;
			}
			else
				free (cmd);
		}
		y++;
	}
	if (exist == 0)
	{
		perror("Command not foundB");
		exit (127);
	}
	if (perm == 1)
		return (cmd);
	else
	{
		perror("Permission denied");
		exit (126);
	}
	return (NULL);
}

char	*check_path_ch(char **paths, char **comand)
{
	int		y;
	char	*cmd;
	char	*cmdp;

	y = 0;
	cmd = NULL;
	while (paths[y] != NULL)
	{
		cmdp = ft_strjoin(paths[y], "/");
		if (!cmdp)
			return (NULL);
		cmd = ft_strjoin(cmdp, comand[0]);
		free (cmdp);
		if (!cmd)
			return (NULL);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			free(cmd);
		y++;
	}
	return (NULL);
}
