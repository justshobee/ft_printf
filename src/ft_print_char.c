/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:29:33 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/02 17:39:37 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	char	uc;

	uc = (unsigned char)c;
	return (write(1, &uc, 1));
}

int	ft_print_percent(void)
{
	return (ft_print_char('%'));
}
