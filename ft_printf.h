/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:35:08 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/04 15:45:43 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_dispatch(char c, va_list list);
int		ft_print_char(int c);
int		ft_print_percent(void);
int		ft_print_str(char *s);
int		ft_print_base(unsigned long n, const char *base);
int		ft_print_int(int nbr);
int		ft_print_unsigned(unsigned int nbr);
int		ft_print_hex(unsigned int n, char c);
int		ft_print_ptr(void *ptr);

#endif
