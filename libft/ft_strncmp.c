/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:52:45 by martorre          #+#    #+#             */
/*   Updated: 2023/09/18 17:40:59 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	while ((str[i] != '\0' || str1[i] != '\0') && i < n)
	{
		if (str[i] != str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
		char			s1[] = "\200";
		char			s2[] = "\0";
		unsigned int	i = 0;
		unsigned int	n = 4;
		i = strncmp(s1,s2,n);
		//i = ft_strncmp(s1,s2,n);
		printf("S1 = %s\n",s1);
		printf("S2 = %s\n",s2);
		printf("Em torna STRCMP = %d\n",i);
}*/