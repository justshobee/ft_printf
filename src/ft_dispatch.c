/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:07:45 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/04 15:46:35 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_unknown(char c)
{
	int	a;
	int	b;

	a = ft_print_char('%');
	if (a == -1)
		return (-1);
	b = ft_print_char(c);
	if (b == -1)
		return (-1);
	return (a + b);
}

int	ft_dispatch(char c, va_list list)
{
	if (c == 'c')
		return (ft_print_char((char)va_arg(list, int)));
	else if (c == '%')
		return (ft_print_percent());
	else if (c == 's')
		return (ft_print_str(va_arg(list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(list, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(list, unsigned int), c));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(list, void *)));
	return (ft_print_unknown(c));
}
