/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:01:37 by martorre          #+#    #+#             */
/*   Updated: 2023/10/11 11:17:16 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversations(char c, va_list arg_ptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg_ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg_ptr, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_free_itoa(va_arg(arg_ptr, int)));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF",
				42));
	else if (c == 'u')
		return (ft_free_nosig(va_arg(arg_ptr, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(arg_ptr, unsigned int), "0123456789abcdef",
				42));
	else if (c == 'p')
	{
		return (ft_putnbr_hex_v(va_arg(arg_ptr, unsigned long),
				"0123456789abcdef", testprint()));
	}
	return (0);
}

int	start(char *str, int out, int cont, va_list arg_ptr)
{
	int	i;

	i = -1;
	while (str[++i] && out != -1)
	{
		if (str[i] != '%')
		{
			out = ft_putchar(str[i]);
			if (out == -1)
				cont = -1;
			else
				cont += out;
		}
		if (str[i] == '%' && out != -1)
		{
			out = conversations(str[++i], arg_ptr);
			if (out == -1)
				cont = -1;
			else
				cont += out;
		}
	}
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg_ptr;
	int		out;
	int		cont;

	out = 0;
	cont = 0;
	va_start(arg_ptr, str);
	cont = start((char *)str, out, cont, arg_ptr);
	return (cont);
}
