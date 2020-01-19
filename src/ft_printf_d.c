/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:54:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/19 14:52:44 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_setd(t_struct *yeet, int arg, int neg, char c)
{
	int		len;

	len = ft_intlen(arg);
	(neg == 1) ? len++ : 0;
	if (yeet->flags == '-')
	{
		(neg == 1) ? yeet->retcount += buffaddchar(yeet, '-') : 0;
		while (yeet->precision > len++)
			yeet->retcount += buffaddchar(yeet, '0');
		yeet->retcount += buffaddnbr(yeet, arg, -1);
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
	}
	else if (yeet->flags != '-')
	{
		if (c == '0')
			(neg == 1) ? yeet->retcount += buffaddchar(yeet, '-') : 0;
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
		if (c != '0')
			(neg == 1) ? yeet->retcount += buffaddchar(yeet, '-') : 0;
		while (yeet->precision > len++)
			yeet->retcount += buffaddchar(yeet, '0');
		yeet->retcount += buffaddnbr(yeet, arg, -1);
	}
}

int					ft_printf_d(t_struct *yeet, int arg)
{
	char	c;
	int		lenarg;
	int		i;
	int		neg;

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
	ft_setd(yeet, arg, neg, c);
	return (0);
}
