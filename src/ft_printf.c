/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:04:14 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 11:39:13 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include "../libft/libft.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_struct	yeet;

	va_start(ap, str);
	// init val
	yeet.index = 0;
	yeet.retcount = 0;
	yeet.str = (char *)str;
	ft_memset(yeet.buff, '0', B_SIZE);
	// _____________
	ft_parsing(&yeet, ap);
	write(1, yeet.buff, yeet.index);
	va_end(ap);
	return (yeet.retcount);
}