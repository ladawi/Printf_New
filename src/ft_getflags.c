/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:49:54 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/19 14:01:21 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_setyeettype(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (ft_checkchar(yeet->str[yeet->strid + i]) == 0)
	{
		if ((ft_isdigit(yeet->str[yeet->strid + i]) == 0)
			&& yeet->str[yeet->strid + i] != '-'
				&& yeet->str[yeet->strid + i] != '.'
					&& yeet->str[yeet->strid + i] != '*')
		{
			yeet->type = yeet->str[yeet->strid + i];
			return (0);
		}
		i++;
	}
	yeet->type = yeet->str[yeet->strid + i];
	return (1);
}

int		ft_setyeetflags(t_struct *yeet, va_list ap)
{
	int i;

	i = 0;
	while ((yeet->str[yeet->strid + i] == '0')
		|| (yeet->str[yeet->strid + i] == '-'))
	{
		if (yeet->str[yeet->strid + i] == '-')
			yeet->flags = '-';
		if (yeet->str[yeet->strid + i] == '0' && yeet->flags != '-')
			yeet->flags = '0';
		i++;
	}
	yeet->strid += i;
	return (0);
}

int		ft_setyeetwidth(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (ft_isdigit(yeet->str[yeet->strid + i]) == 1
		&& yeet->str[yeet->strid + i] != 0)
		i++;
	if (yeet->str[yeet->strid + i] == '*')
	{
		yeet->width = va_arg(ap, int);
		if (yeet->width < 0)
		{
			yeet->width = -yeet->width;
			yeet->flags = '-';
		}
	}
	else
		yeet->width = ft_atoi(yeet->str + yeet->strid);
	if (yeet->width < -1)
		yeet->width = -yeet->width;
	return (i);
}

int		ft_setyeetprecision(t_struct *yeet, va_list ap)
{
	int		i;
	int		z;

	z = 0;
	i = 0;
	while (yeet->str[yeet->strid + i] != '.'
		&& ft_checkchar(yeet->str[yeet->strid + i]) == 0)
		i++;
	while (yeet->str[yeet->strid + i + z] == '.')
		z++;
	if (z != 0)
	{
		if (yeet->str[yeet->strid + i + z] == '*')
		{
			yeet->precision = va_arg(ap, int);
			if (yeet->precision < 0)
				yeet->precision = -1;
		}
		else
			yeet->precision = ft_atoi(yeet->str + yeet->strid + i + z);
	}
	yeet->strid += i + z;
	if (yeet->precision < -1)
		yeet->precision = -yeet->precision;
	return (i);
}

int		ft_getflags(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	yeet->strid++;
	yeet->flags = -1;
	yeet->width = -1;
	yeet->precision = -1;
	if (ft_setyeettype(yeet, ap) != 0)
	{
		i += ft_setyeetflags(yeet, ap);
		i += ft_setyeetwidth(yeet, ap);
		i += ft_setyeetprecision(yeet, ap);
	}
	while (yeet->str[yeet->strid] != yeet->type)
		yeet->strid++;
	return (i);
}
