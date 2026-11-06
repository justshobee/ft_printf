/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:41:45 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/04 15:47:05 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_print_base(unsigned long n, const char *base)
{
	unsigned long	div;
	unsigned long	blen;
	int				count;
	int				re;

	blen = ft_strlen(base);
	if (blen < 2)
		return (-1);
	div = 1;
	count = 0;
	while (div <= (n / blen))
		div *= blen;
	while (div > 0)
	{
		re = ft_print_char(base[n / div]);
		if (re == -1)
			return (-1);
		count += re;
		n = n % div;
		div = div / blen;
	}
	return (count);
}

int	ft_print_hex(unsigned int n, char c)
{
	if (c == 'x')
		return (ft_print_base((unsigned long)n, "0123456789abcdef"));
	return (ft_print_base((unsigned long)n, "0123456789ABCDEF"));
}
