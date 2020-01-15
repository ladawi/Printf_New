/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:53:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/15 21:24:36 by ladawi           ###   ########.fr       */
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
			yeet->retcount += buffaddchar(yeet, yeet->str[i]);
			i++;
		}
	}
	return (0);
}