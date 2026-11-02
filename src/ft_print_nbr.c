/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:48:03 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/02 10:16:15 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_int(int nbr)
{
	long	n;
	int		count;

	n = nbr;
	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	count += ft_print_base((unsigned long)n, "0123456789");
	return (count);
}

int		ft_print_unsigned(unsigned int nbr)
{
	return (ft_print_base((unsigned long)nbr, "0123456789"));
}
