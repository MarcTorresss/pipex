/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:58:17 by martorre          #+#    #+#             */
/*   Updated: 2023/08/21 15:06:13 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	acum;

	i = 0;
	acum = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && acum == 0)
	{
		acum = s1[i] - s2[i];
		i++;
	}
	return (acum);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	s1[] = "hola";
	char	s2[] = "hslaa";
	int		i = 0;
	//i = strcmp(s1,s2);
	i = ft_strcmp(s1,s2);
	printf("S1 = %s\n",s1);
	printf("S2 = %s\n",s2);
	printf("Em torna STRCMP = %d\n",i);
}*/
