/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:04:14 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/19 15:02:26 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include "../libft/libft.h"

void	ft_inityeet(t_struct *yeet, char *str)
{
	yeet->index = 0;
	yeet->retcount = 0;
	yeet->str = (char *)str;
	yeet->strid = 0;
	yeet->precision = -1;
	ft_memset(yeet->buff, 0, B_SIZE);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_struct	yeet;

	va_start(ap, str);
	ft_inityeet(&yeet, str);
	ft_scanstr(&yeet, ap);
	write(1, yeet.buff, yeet.index);
	va_end(ap);
	return (yeet.retcount);
}
