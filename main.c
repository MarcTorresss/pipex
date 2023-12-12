/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:01:27 by martorre          #+#    #+#             */
/*   Updated: 2023/12/12 14:43:24 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **ft_envpaths(char  **env)
{
    int     y;
    char    *path;
    char    **paths;

    y = 0;
    while (env[y] != NULL)
    {
        if (ft_strnstr(env[y], "PATH=", 5) != 0)
            path = ft_strnstr(env[y], "PATH=", 5);
        y++;
    }
    paths = ft_split(path, ':');
    paths[0] = ft_strchr(paths[0], '/');
    /*y = 0;
    while (paths[y] != NULL)
    {
        ft_printf("%s\n", paths[y]);
        y++;
    }*/
    return (paths);
}

int check_errors()
{
    if (errno == EACCES)
    {
        perror("Permisdion denied");
        exit(126);
    }
    else if (errno == ENOENT)
    {
       perror("Command not found");
        exit(127);
    }
    exit(EXIT_SUCCESS);
}
char    *check_path(char **paths, char **comand)
{
    int     y;
    char    *cmd;

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
int ft_execve(t_pipex *stp, char **envp, char **comand)
{
    char    *cmd;

    cmd = check_path(stp->paths, comand);
    if (cmd != NULL)
        execve(cmd, comand, envp);
    return (check_errors());
}

int    child_process(t_pipex *stp, char **argv, char **envp)
{
    dup2(stp->f1, STDIN_FILENO); // f1 nuvea entrada estandar
    dup2(stp->end[1], STDOUT_FILENO); // end[1] nueva salida estandar
    close(stp->end[0]); //cerramos lo que no se utilliza
    close(stp->f1);
    stp->com1 = ft_split(argv[2], ' ');
    return (ft_execve(stp, envp, stp->com1));
}

int    parent_process(t_pipex *stp, char **argv, char **envp)
{
    int     status;

    waitpid(-1, &status, 0); //Pid del hijo
    /*if ((WIFEXITED(status)) == 1)
        exit (WEXITSTATUS(status));*/
    dup2(stp->f2, STDOUT_FILENO);
    dup2(stp->end[0], STDIN_FILENO);
    close(stp->end[1]);
    close(stp->f2);
    stp->com2 = ft_split(argv[3], ' ');
    return (ft_execve(stp, envp, stp->com2));
}

int    pipex(t_pipex *stp, char **argv, char **envp)
{
    pipe(stp->end); //obtenemos y guardamos dos fds linkados
    stp->parent = fork(); //pid del hijo
    if (stp->parent < 0)
        return (perror("Fork: "), -1); // que hace perror?
    if (!stp->parent) // si fork() debuelve 0, estamos en el proceso hijo
        child_process(stp, argv, envp);
    return (parent_process(stp, argv, envp));
}

int main(int argc, char **argv, char **envp)
{
    t_pipex stp;
    
    stp.f1 = 0;
    stp.f2 = 0;
    if (argc != 5)
        return (ft_printf("Too many arguments :/\n"), -1);
    if (argv[2] == NULL || argv[3] == NULL)
        return (ft_printf("Invalid Comand :/\n"), -1);
    else
    {
        if (access(argv[1], R_OK) == 0)
        {
            stp.f1 = open(argv[1], O_RDONLY);
            /*if (access(argv[4], R_OK) == 0)
            {*/
            stp.f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
            if (stp.f1 < 0 || stp.f2 < 0)
                return (-1);
            stp.paths = ft_envpaths(envp);
            return (pipex(&stp, argv, envp));
            close(stp.f2);
           // }
            close(stp.f1);
        }
    }
    //ft_printf("\n%d\n", check_errors());
    return (check_errors());
}
