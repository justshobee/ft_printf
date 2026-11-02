/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:48:27 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/02 14:28:52 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		list;
	char		*s;
	int			i;
	int			count;

	va_start(list, fmt);
	i = 0;
	count = 0;
	s = (char *)fmt;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_dispatch(s[i + 1], list);
			i++;
		}
		else
			count += ft_print_char(s[i]);
		i++;
	}
	return (count);
}
