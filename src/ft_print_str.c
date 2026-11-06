/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:37:01 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/02 14:28:21 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int		i;
	int		count;
	int		re;

	if (s == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	count = 0;
	while (s[i])
	{
		re = ft_print_char(s[i]);
		if (re == -1)
			return (-1);
		count += re;
		i++;
	}
	return (count);
}
