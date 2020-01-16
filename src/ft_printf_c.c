/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:47:10 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 17:22:59 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_c(t_struct *yeet, va_list ap)
{
	if (yeet->flags == '-')
		yeet->retcount+= buffaddchar(yeet, va_arg(ap, int));
	while (yeet->width-- > 1)
	{
		if (yeet->flags == '0')
			yeet->retcount+= buffaddchar(yeet, '0');
		else 
			yeet->retcount+= buffaddchar(yeet, ' ');
	}
	if (yeet->flags != '-')
		yeet->retcount+= buffaddchar(yeet, va_arg(ap, int));
	return (0);
}