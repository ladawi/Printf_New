/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:49:54 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/15 22:38:44 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_getflags(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	yeet->index++;  // remove %
	/*                           GetFlags : "flags"                           */
	while ((yeet->str[yeet->index] != 'd')
		&& (yeet->str[yeet->index] <= '0' || yeet->str[yeet->index] > '9'))
	{
		if (yeet->str[yeet->index] == '-')
			yeet->flags = yeet->str[yeet->index];
		if (yeet->str[yeet->index] == '0' && yeet->flags != '-')
			yeet->flags = yeet->str[yeet->index];
		yeet->index++;
	}
	/*                                                                        */
	/*                           GetFlags : "width"                           */
	while ((yeet->str[yeet->index] != 'd') && (yeet->str[yeet->index] != '.'))
	{
		yeet->index++;
		i++;
	}
	yeet->width = ft_atoi(yeet->str + yeet->index - i);
	/*                                                                        */
	/*                         GetFlags : "precision"                         */
	yeet->index++;  // remove .
	i = 0;
	while (yeet->str[yeet->index] != 'd')
	{
		yeet->index++;
		i++;
	}
	yeet->precision = ft_atoi(yeet->str + yeet->index - i);
	/*                                                                        */
	/*                                                                        */
	printf("[%c][%d][%d]\n", yeet->flags, yeet->width, yeet->precision);
	return (0);
}
