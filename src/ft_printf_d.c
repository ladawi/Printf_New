/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:54:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/17 20:14:03 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf_d(t_struct *yeet, int arg)
{
	char	c;
	int		lenarg;
	int		i;
	
	i = 0;
	lenarg = ft_intlen(arg);
	c = (yeet->flags == '0' && yeet->precision == -1) ? '0' : ' ';
	yeet->width -= (yeet->precision > lenarg) ? yeet->precision : lenarg;
	if (arg < 0)
	{
		yeet->retcount += buffaddchar(yeet, '-');
		arg = -arg;
		lenarg++;
	}
	if (yeet->flags == '-')
	{
		while (yeet->precision > lenarg++)
			yeet->retcount+= buffaddchar(yeet, '0');
		yeet->retcount += buffaddnbr(yeet, arg, -1);
		while (yeet->width-- > 0)
			yeet->retcount+= buffaddchar(yeet, c);
	}
	else if (yeet->flags != '-')
	{
		while (yeet->width-- > 0)
			yeet->retcount+= buffaddchar(yeet, c);
		while (yeet->precision > lenarg++)
			yeet->retcount+= buffaddchar(yeet, '0');
		yeet->retcount += buffaddnbr(yeet, arg, -1);
	}
	return (0);
}