/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:11:15 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/19 14:15:45 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_setx(t_struct *yeet, unsigned int arg, int lenarg, char c)
{
	int		i;

	i = 0;
	if (yeet->flags == '-')
	{
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		if (!((yeet->precision > 0) && arg == 0))
			yeet->retcount += buffaddnbr(yeet, arg, -1);
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
	}
	else if (yeet->flags != '-')
	{
		while (yeet->width > i++)
			yeet->retcount += buffaddchar(yeet, c);
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		if (!((yeet->precision > 0) && arg == 0))
			yeet->retcount += buffaddnbr(yeet, arg, -1);
	}
	return (0);
}

int			ft_printf_x(t_struct *yeet, unsigned int arg)
{
	char	c;
	int		lenarg;
	int		i;

	i = 0;
	lenarg = ft_intlenbase(arg, 16);
	c = (yeet->flags == '0' && yeet->precision == -1) ? '0' : ' ';
	(arg == 0) ? lenarg-- : 0;
	if (arg == 0 && yeet->precision == -1)
		yeet->width--;
	yeet->width -= (yeet->precision > lenarg) ? yeet->precision : lenarg;
	ft_setx(yeet, arg, lenarg, c);
	return (0);
}
