/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:49:40 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/17 20:10:42 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_u(t_struct *yeet, unsigned int arg)
{
	int		lenarg;
	char	c;

	c = (yeet->flags == '0' && yeet->precision == -1) ? '0' : ' ';
	lenarg = ft_intlen(arg);
	yeet->width -= (yeet->precision > lenarg) ? yeet->precision : lenarg;
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