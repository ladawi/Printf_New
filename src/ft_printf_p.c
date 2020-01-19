/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:05:57 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/19 12:13:06 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf_p(t_struct *yeet, unsigned long int arg)
{
	char	c;
	int		lenarg;
	int		i;
	char	*prefix;
	char	*hex;

	i = 0;
	hex = "0x";
	lenarg = ft_intlenbase(arg, 16);
	c = (yeet->flags == '0' && yeet->precision == 0) ? '0' : ' ';
	if (!(yeet->precision == 0 && arg == 0))
		yeet->width -= (yeet->precision > lenarg) ? yeet->precision : lenarg;
	yeet->width -= ft_strlen(hex);
	if (yeet->flags == '-')
	{
		yeet->retcount += buffaddstr(yeet, hex, -1);
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		yeet->retcount += buffaddadress(yeet, arg, -1);
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
	}
	else if (yeet->flags != '-')
	{
		(yeet->flags == '0') ? yeet->retcount += buffaddstr(yeet, hex, -1) : 0;
		while (yeet->width-- > 0)
			yeet->retcount += buffaddchar(yeet, c);
		(yeet->flags != '0') ? yeet->retcount += buffaddstr(yeet, hex, -1) : 0;
		while (yeet->precision > lenarg++)
			yeet->retcount += buffaddchar(yeet, '0');
		yeet->retcount += buffaddadress(yeet, arg, -1);
	}
	return (0);
}
