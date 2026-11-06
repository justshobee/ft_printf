/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:48:03 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/04 15:25:37 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int nbr)
{
	long	n;
	int		count;
	int		re;

	n = nbr;
	count = 0;
	if (n < 0)
	{
		re = ft_print_char('-');
		if (re == -1)
			return (-1);
		count += re;
		n = -n;
	}
	re = ft_print_base((unsigned long)n, "0123456789");
	if (re == -1)
		return (-1);
	count += re;
	return (count);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		re;

	re = ft_print_base((unsigned long)nbr, "0123456789");
	if (re == -1)
		return (-1);
	return (re);
}
