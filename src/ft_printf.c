/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:48:27 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/02 17:50:17 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		list;
	int			i;
	int			count;

	if (s == NULL)
		return (-1);
	va_start(list, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			count += ft_dispatch(s[i], list);
		}
		else
			count += ft_print_char(s[i]);
		i++;
	}
	va_end(list);
	return (count);
}
