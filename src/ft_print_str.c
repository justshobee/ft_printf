/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:37:01 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/01 20:47:31 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_str(char *s)
{
	int		i;

	if (s == NULL)
		return (write(1 "(null)", 6));
	i = 0;
	while (s[i])
	{
		ft_print_char(s[i]);
		i++;
	}
	return (i);
}
