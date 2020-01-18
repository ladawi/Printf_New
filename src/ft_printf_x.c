/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:11:15 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 11:28:40 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf_x(t_struct *yeet, int arg)
{
	char	c;
	int		lenarg;
	int		i;

	i = 0;
	lenarg = ft_intlenbase(arg, 16);
	c = (yeet->flags == '0' && yeet->precision == 0) ? '0' : ' ';
	yeet->width -= (yeet->precision > lenarg) ? yeet->precision : lenarg;
	if (arg < 0)
	{
		yeet->retcount += buffaddchar(yeet, '-');
		arg = 0xffffffff - arg;
		lenarg++;
	}
	if (yeet->flags == '-')
	{
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		yeet->retcount += buffaddnbr(yeet, arg, -1);
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
	}
	else if (yeet->flags != '-')
	{
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		yeet->retcount += buffaddnbr(yeet, arg, -1);
	}
	return (0);
}
