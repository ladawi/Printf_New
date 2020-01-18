/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:04:14 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 17:48:07 by ladawi           ###   ########.fr       */
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
	yeet.index = 0;
	yeet.retcount = 0;
	yeet.str = (char *)str;
	yeet.strid = 0;
	yeet.precision = -1;
	ft_memset(yeet.buff, 0, B_SIZE);
	ft_scanstr(&yeet, ap);
	write(1, yeet.buff, yeet.index);
	va_end(ap);
	return (yeet.retcount);
}
