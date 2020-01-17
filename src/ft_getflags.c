/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:49:54 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/17 19:36:54 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_setyeettype(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (ft_checkchar(yeet->str[yeet->strid + i]) == 0)
	{
		if ((ft_isdigit(yeet->str[yeet->strid + i]) == 0) && yeet->str[yeet->strid + i] != '-'
			&& yeet->str[yeet->strid + i] != '.')
		{
			yeet->type = yeet->str[yeet->strid + i];
			return (0);
		}
		i++;
	}
	yeet->type = yeet->str[yeet->strid + i];
	// printf("[yeet->str[yeet->strid + i] = %c]\n", yeet->str[yeet->strid + i]);
	return (1);
}

int		ft_setyeetflags(t_struct *yeet, va_list ap)
{
	int i;

	i = 0;
	while ((yeet->str[yeet->strid + i] == '0') || (yeet->str[yeet->strid + i] == '-'))
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
	while (ft_isdigit(yeet->str[yeet->strid + i]) == 1 && yeet->str[yeet->strid + i] != 0)
		i++;
	yeet->width = ft_atoi(yeet->str + yeet->strid);
	// yeet->width = (yeet->width > 0) ? yeet->width : -yeet->width;
	return (i);
}

int		ft_setyeetprecision(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (yeet->str[yeet->strid + i] != '.' && ft_checkchar(yeet->str[yeet->strid + i]) == 0)		// remove .
		i++;
	while (yeet->str[yeet->strid + i] == '.')		// remove .
		i++;
	// printf("[%d] ||", ft_atoi(yeet->str + yeet->strid + i));
	if (i != 0)
		yeet->precision = ft_atoi(yeet->str + yeet->strid + i);
	yeet->strid += i;
	return (i);
}

int		ft_getflags(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	yeet->strid++;  // remove %
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
	// printf("// yeet->strid = %d [%s][%c][flags = %c][width = %d][pre = %d] \\\\\n", yeet->strid, yeet->str + yeet->strid, yeet->str[yeet->strid],yeet->flags, yeet->width, yeet->precision);
	return (i);
}
