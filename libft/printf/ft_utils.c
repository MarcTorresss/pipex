/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:46:55 by martorre          #+#    #+#             */
/*   Updated: 2023/10/11 11:17:20 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
	return (0);
}

int	ft_free_itoa(int n)
{
	char	*str;
	int		out;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	out = ft_putstr(str);
	free(str);
	return (out);
}

int	ft_free_nosig(int n)
{
	char	*str;
	int		out;

	str = ft_nosig(n);
	if (!str)
		return (-1);
	out = ft_putstr(str);
	free(str);
	return (out);
}

int	testprint(void)
{
	int	out;

	out = ft_putstr("0x");
	return (out);
}
