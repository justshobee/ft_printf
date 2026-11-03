/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:41:45 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/03 09:08:20 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_print_base(unsigned long n, const char *base)
{
	unsigned long	div;
	int				count;
	int				blen;

	div = 1;
	count = 0;
	blen = ft_strlen(base);
	while (div <= (n / blen))
		div *= blen;
	while (div > 0)
	{
		count += ft_print_char(base[n / div]);
		n = n % div;
		div = div / blen;
	}
	return (count);
}

int	ft_print_hex(unsigned int n, char c)
{
	if (c == 'x')
		return (ft_print_base((unsigned long)n, "0123456789abcdef"));
	else
		return (ft_print_base((unsigned long)n, "0123456789ABCDEF"));
}
