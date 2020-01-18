/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:54:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 17:13:17 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf_d(t_struct *yeet, int arg)
{
	char	c;
	int		lenarg;
	int		i;
	int 	neg;
	
	i = 0;
	neg = 0;
	lenarg = ft_intlen(arg);
	c = (yeet->flags == '0' && yeet->precision == -1) ? '0' : ' ';
	if (arg < 0)
	{
		neg = 1;
		arg = -arg;
		lenarg++;
		yeet->precision++;
	}
	yeet->width -= (yeet->precision > lenarg) ? yeet->precision : lenarg;
	if (((yeet->precision == 0) && arg == 0))
		yeet->width++;
	if (yeet->flags == '-')
	{
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		(neg == 1 ) ? yeet->retcount += buffaddchar(yeet, '-') : 0;
		yeet->retcount += buffaddnbr(yeet, arg, -1);
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
	}
	else if (yeet->flags != '-')
	{
		if (c == '0')
			(neg == 1 ) ? yeet->retcount += buffaddchar(yeet, '-') : 0;
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		if (c != '0')
			(neg == 1 ) ? yeet->retcount += buffaddchar(yeet, '-') : 0;
		yeet->retcount += buffaddnbr(yeet, arg, -1);
	}
	return (0);
}