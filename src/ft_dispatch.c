/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:07:45 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/02 17:35:52 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else
		return (ft_print_char('%') + ft_print_char(c));
}
