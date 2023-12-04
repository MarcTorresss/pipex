/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:58:12 by martorre          #+#    #+#             */
/*   Updated: 2023/09/20 15:07:02 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (i < len && start < ft_strlen(s) && s[start + i])
		i++;
	new = malloc(i +1);
	if (!new)
	{
		return (0);
		free(new);
	}
	while (j < i && start < ft_strlen((char *)s))
	{
		new[j] = s[start + j];
		j++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main (void)
{
	char			*s;
	unsigned int	start = 3;
	size_t			len = 3;
	s = ft_substr("Tardes", start, len);
	printf("%s", s);
}*/
