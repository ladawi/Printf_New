/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:49:54 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 17:51:41 by ladawi           ###   ########.fr       */
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
	while (((yeet->str[yeet->strid + i + 1] == '-' ) || (yeet->str[yeet->strid + i + 1] == '0' ))  && (ft_checkchar(yeet->str[yeet->strid + i + 1]) != 1))
		i++;
		// printf("%d\n", i);
	if (yeet->str[yeet->strid + i] == '0' && yeet->flags != '-')
	{
		yeet->flags = yeet->str[yeet->strid + i];
		yeet->strid++;
	}
	if (yeet->str[yeet->strid + i] == '-')
	{
		yeet->flags = yeet->str[yeet->strid + i];
		yeet->strid++;
	}
	while (i--)
		yeet->strid++;
	// printf("<%s>\n", yeet->str + yeet->strid);
	return (0);
}

int		ft_setyeetwidth(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (ft_checkchar(yeet->str[yeet->strid]) == 0 && (yeet->str[yeet->strid] != '.'))
	{
		yeet->strid++;
		i++;
	}
	yeet->width = ft_atoi(yeet->str + yeet->strid - i);
	// yeet->width = (yeet->width > 0) ? yeet->width : -yeet->width;
	return (i);
}

int		ft_setyeetprecision(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	if (yeet->str[yeet->strid] == '.')		// remove .
		yeet->strid++;
	while (ft_checkchar(yeet->str[yeet->strid]) == 0)
	{
		yeet->strid++;
		i++;
	}
	yeet->precision = ft_atoi(yeet->str + yeet->strid - i);
	return (i);
}

int		ft_getflags(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	yeet->strid++;  // remove %
	if (ft_setyeettype(yeet, ap) != 0)
	{
		i += ft_setyeetflags(yeet, ap);
		i += ft_setyeetwidth(yeet, ap);
		i += ft_setyeetprecision(yeet, ap);
	}
	printf("[%c]\n", yeet->type);
	yeet->type = yeet->str[yeet->strid];
	return (i);
}
