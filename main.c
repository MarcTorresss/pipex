/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:01:27 by martorre          #+#    #+#             */
/*   Updated: 2023/12/04 18:53:55 by martorre         ###   ########.fr       */
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

int main(int argc, char **argv, char **env)
{
    char    **paths;
    int y = 0;
    
    (void) argc;
    (void) argv;
    if (argc != 3)
        ft_printf("Too many arguments :/\n");
    else
        paths = ft_envpaths(env);
}
