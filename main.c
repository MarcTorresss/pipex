/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:01:27 by martorre          #+#    #+#             */
/*   Updated: 2023/12/05 15:30:17 by martorre         ###   ########.fr       */
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

void    child_process(int f1, char *cmd1, int *end)
{
    dup2(f1, STDIN_FILENO); // f1 nuvea entrada estandar
    dup2(end[1], STDOUT_FILENO); // end[1] nueva salida estandar
    close(end[0]); //cerramos lo que no se utilliza
    close(f1);
    //funcion para ejecutar por cada ruta
}

void    parent_process(int f2, char *cmd2, int *end)
{
    int status;
    waitpid(-1, &status, 0); // -1 para checkear que el hijo termine
    dup2(f2, STDOUT_FILENO);
    dup2(end[0], STDIN_FILENO);
    close(end[1]);
    close(f2);
    //funcion para ejecutar por cada ruta
}

void    pipex(int f1, int f2, char **argv, char **paths)
{
    int     end[2];
    pid_t   parent;

    pipe(end); //obtenemos y guardamos dos fds
    parent = fork();
    if (parent < 0)
        return (perror("Fork"));
    if (!parent) // si fork() debuelve 0, estamos en el proceso hijo
        child_process(f1, argv[2], end);
    else
        parent_process(f2, argv[3], end);
}

int start_exv(char **path, char *cmd1, char *cmd2)
{
    int     y;
    int     ok;
    char    **com1;
    char    **com2;

    com1 = ft_split(cmd1, ' ');
    com2 = ft_split(cmd2, ' ');
    y = 0;
    ok = 0;

    while (path[y] != NULL)
    {
        if (access(ft_strjoin(path[y], com1[0]), F_OK) == 0)
        {
            ok = 1;
        }
        y++;
    }
    if (ok == 0)
        return (ft_printf("Error: Command not found"), -1);
    else 
        return (0);
}

int main(int argc, char **argv, char **env)
{
    char    **paths;
    int     f1;
    int     f2;
    
    f1 = 0;
    f2 = 0;
    if (argc != 3)
        return (ft_printf("Too many arguments :/\n"), -1);
    else
    {
        f1 = open(argv[1], O_RDONLY);
        f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
        if (f1 < 0 || f2 < 0)
            return (-1);
        paths = ft_envpaths(env);
        pipex(f1, f2, argv, paths);
        return (0);
    }
}
