/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:48:27 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/04 15:46:08 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char *s, va_list list)
{
	int	i;
	int	c;
	int	r;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '%' && !s[i + 1])
			return (-1);
		if (s[i] == '%')
			r = ft_dispatch(s[++i], list);
		else
			r = ft_print_char(s[i]);
		if (r == -1)
			return (-1);
		c += r;
		i++;
	}
	return (c);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		ret;

	if (!s)
		return (-1);
	va_start(list, s);
	ret = ft_parse(s, list);
	va_end(list);
	return (ret);
}
