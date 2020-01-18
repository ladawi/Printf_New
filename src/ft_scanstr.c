/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:53:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 13:27:49 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_scanstr(t_struct *yeet, va_list ap)
{
	int		i;

	i = 0;
	while (yeet->str[yeet->strid] != 0)
	{
		// printf("[%c]\n", yeet->str[yeet->strid]);
		if (yeet->str[yeet->strid] == '%')
		{
			ft_getflags(yeet, ap);
			ft_parsing(yeet, ap);
		}
		else
		{
			yeet->retcount += buffaddchar(yeet, yeet->str[yeet->strid]);
			yeet->strid++;
		}
	}
	return (0);
}
