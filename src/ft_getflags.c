/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:49:54 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 11:37:40 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_setflags(t_struct *yeet, va_list ap)
{
	while (ft_checkchar(yeet->str[yeet->index]) == 0 
		&& (ft_isdigit(yeet->str[yeet->index]) == 0 && yeet->str[yeet->index] != '-')
			&& (yeet->str[yeet->index] <= '0' || yeet->str[yeet->index] > '9'))
	{
		if (yeet->str[yeet->index] == '-')
			yeet->flags = yeet->str[yeet->index];
		if (yeet->str[yeet->index] == '0' && yeet->flags != '-')
			yeet->flags = yeet->str[yeet->index];
		yeet->index++;
	}
	return (0);
}

int		ft_setwidth(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (ft_checkchar(yeet->str[yeet->index]) == 0 && (yeet->str[yeet->index] != '.'))
	{
		yeet->index++;
		i++;
	}
	yeet->width = ft_atoi(yeet->str + yeet->index - i);
	return (0);
}

int		ft_setprecision(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	if (yeet->str[yeet->index] == '.')		// remove .
		yeet->index++;
	while (ft_checkchar(yeet->str[yeet->index]) == 0)
	{
		yeet->index++;
		i++;
	}
	yeet->precision = ft_atoi(yeet->str + yeet->index - i);
	return (0);
}

int		ft_getflags(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	yeet->index++;  // remove %
	ft_setflags(yeet, ap);
	ft_setwidth(yeet, ap);
	ft_setprecision(yeet, ap);
	return (0);
}
