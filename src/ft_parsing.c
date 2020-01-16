/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:53:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 11:44:04 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parsing(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (yeet->str[i] != 0)
	{
		if (yeet->str[i] == '%')
		{
			ft_getflags(yeet, ap);
			i++;
		}
		else 
		{
			yeet->retcount += buffaddchar(yeet, yeet->str[yeet->index]);
			i++;
		}
		// printf("// yeet->index = %d [%s][%c][%c][%d][%d] \\\\\n", yeet->index, yeet->buff + yeet->index, yeet->str[yeet->index],yeet->flags, yeet->width, yeet->precision);

	}
	return (0);
}