/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:01:27 by martorre          #+#    #+#             */
/*   Updated: 2023/12/11 18:29:21 by martorre         ###   ########.fr       */
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

int    ft_execve(t_pipex *stp, char **envp, char **comand)
{
    int     y;
    char    *cmd;
    int     qtt;

    qtt = 0;
    y = 0;
    while (stp->paths[y] != NULL)
    {
        cmd = ft_strjoin(stp->paths[y], "/");
        if (!cmd)
            return (-1);
        cmd = ft_strjoin(cmd, comand[0]);
        if (!cmd)
            return (-1);
        qtt = execve(cmd, comand, envp);
        free(cmd);
        y++;
    }
    return (qtt);
}

int    child_process(t_pipex *stp, char **argv, char **envp)
{
    dup2(stp->f1, STDIN_FILENO); // f1 nuvea entrada estandar
    dup2(stp->end[1], STDOUT_FILENO); // end[1] nueva salida estandar
    close(stp->end[0]); //cerramos lo que no se utilliza
    close(stp->f1);
    stp->com1 = ft_split(argv[2], ' ');
    //ft_printf("\n\n\n%d\n\n\n", ft_execve(stp, envp, stp->com1));
    ft_execve(stp, envp, stp->com1);
    exit(EXIT_FAILURE);
    return (0);
}

int    parent_process(t_pipex *stp, char **argv, char **envp)
{
    int     status;

    waitpid(-1, &status, 0); //TIENES EL PID DEL HIJO ASI QUE A MIRAR CUAL ES NO HAGAS CERDADAS
    dup2(stp->f2, STDOUT_FILENO);
    dup2(stp->end[0], STDIN_FILENO);
    close(stp->end[1]);
    close(stp->f2);
    stp->com2 = ft_split(argv[3], ' ');
    ft_printf("\n\n\n%d\n\n\n", ft_execve(stp, envp, stp->com2));
    //ft_execve(stp, envp, stp->com2);
    exit(EXIT_FAILURE);
    return (0);
}

int    pipex(t_pipex *stp, char **argv, char **envp)
{
    int status;

    waitpid(-1, &status, 0);
    if (!(WIFEXITED(status)))
    {
        printf("El proceso hijo ha terminado correctamente.\n");
        printf("Código de salida: %d\n", WEXITSTATUS(status));
    }
    pipe(stp->end); //obtenemos y guardamos dos fds linkados
    stp->parent = fork(); //pid del hijo
    if (stp->parent < 0)
        return (perror("Fork"), -1); // que hace perror?
    if (!stp->parent) // si fork() debuelve 0, estamos en el proceso hijo
        child_process(stp, argv, envp);
    else
        parent_process(stp, argv, envp);
    return (0);
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
        stp.f1 = open(argv[1], O_RDONLY);
        stp.f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
        if (stp.f1 < 0 || stp.f2 < 0)
            return (-1);
        stp.paths = ft_envpaths(envp);
        pipex(&stp, argv, envp);
    }
    return (0);
}
