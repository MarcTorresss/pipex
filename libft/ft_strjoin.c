/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:52:55 by martorre          #+#    #+#             */
/*   Updated: 2023/09/14 12:38:43 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*new;
	int		i;
	int		j;

	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	new = malloc((lens1 + lens2) + 1);
	if (!new)
	{
		return (0);
		free(new);
	}
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
	{
		new[i] = s2[j];
		i++;
	}
	new[i] = '\0';
	return (new);
}
