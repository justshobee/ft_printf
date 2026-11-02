/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:15:53 by mochoubi          #+#    #+#             */
/*   Updated: 2026/11/02 11:43:09 by mochoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main()
{
	int n1 = ft_printf("%p\n",  INT_MAX);
	int n2 = printf("%p\n", (void *)INT_MAX);
	printf("n1 = %d, n2 = %d\n", n1, n2);
}
