/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:35:08 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/01 19:38:40 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H


int		ft_printf(const char *fmt, ...);
int		ft_dispatch(char c, va_list list);
int		ft_print_char();
int		ft_print_percent();
int		ft_print_str();
int		ft_print_int();
int		ft_print_unsigned();
int		ft_print_hex();
int		ft_print_ptr();

#endif
