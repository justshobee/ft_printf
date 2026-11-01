/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:29:33 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/01 20:35:17 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(int c)
{
	return (write(1, (char)&c, 1);
}

int		ft_print_percent()
{
	return (ft_putchar('%'));
}
