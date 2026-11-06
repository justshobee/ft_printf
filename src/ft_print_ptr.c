/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:00:39 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/04 15:24:33 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	p;
	int				count;
	int				re;

	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	p = (unsigned long)ptr;
	count = 0;
	re = ft_print_str("0x");
	if (re == -1)
		return (-1);
	count += re;
	re = ft_print_base(p, "0123456789abcdef");
	if (re == -1)
		return (-1);
	count += re;
	return (count);
}
