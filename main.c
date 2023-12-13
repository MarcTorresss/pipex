/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:01:27 by martorre          #+#    #+#             */
/*   Updated: 2023/12/13 18:36:36 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execve(t_pipex *stp, char **envp, char **comand)
{
	char	*cmd;

	cmd = NULL;
	if (access(comand[0], X_OK) == 0)
		execve(comand[0], comand, envp);
	else
		cmd = check_path(stp->paths, comand);
	if (cmd != NULL)
		execve(cmd, comand, envp);
	else if (stp->numchi == 2)
		return (check_errors());
	return (0);
}

void	child_one(t_pipex *stp, char **argv, char **envp)
{
    stp->numchi = 1;
	dup2(stp->f1, STDIN_FILENO);// f1 nuvea entrada estandar
	dup2(stp->end[1], STDOUT_FILENO);// end[1] nueva salida estandar
	close(stp->end[0]);// cerramos lo que no se utilliza
	close(stp->f1);
	stp->com1 = ft_split(argv[2], ' ');
	ft_execve(stp, envp, stp->com1);
}

int	child_two(t_pipex *stp, char **argv, char **envp)
{
	if (stp->f1 != -1)
	{
        stp->numchi = 2;
		dup2(stp->f2, STDOUT_FILENO);
		dup2(stp->end[0], STDIN_FILENO);
		close(stp->f2);
		close(stp->end[0]);
		stp->com2 = ft_split(argv[3], ' ');
		return (ft_execve(stp, envp, stp->com2));
	}
	exit(0);
}

int	pipex(t_pipex *stp, char **argv, char **envp)
{
	int	status;
	int	ret;

	ret = 0;
	pipe(stp->end);// obtenemos y guardamos dos fds linka
	stp->child1 = fork();// pid del hijo
	if (stp->child1 < 0)
		perror("Pipex: ");
	if (stp->child1 == 0)
		child_one(stp, argv, envp);
	stp->child2 = fork();
	if (stp->child2 < 0)
		perror("Pipex: ");
	if (stp->child2 == 0)
		ret = child_two(stp, argv, envp);
	waitpid(-1, &status, 0);// Pid del hijo
	if ((WIFEXITED(status)) == 1)
		exit(WEXITSTATUS(status));
	close(stp->end[0]);
	close(stp->end[1]);
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	stp;

	stp.f1 = 0;
	stp.f2 = 0;
	if (argc != 5)
	{
		perror("Too many arguments");
		exit(0);
	}
	else
	{
		stp.f1 = open(argv[1], O_RDONLY);
		if (stp.f1 < 0)
			perror("Pipex");
		stp.f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (stp.f2 < 0)
			exit(1);
		stp.paths = ft_envpaths(envp);
		return (pipex(&stp, argv, envp));
		close(stp.f2);
		close(stp.f1);
	}
	return (check_errors());
}
