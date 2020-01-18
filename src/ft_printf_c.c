/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:47:10 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 13:48:05 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_c(t_struct *yeet, int arg)
{
	char	c;

	c = (yeet->flags == '0') ? '0' : ' ';
	if (yeet->flags == '-')
		yeet->retcount += buffaddchar(yeet, arg);
	while (yeet->width-- > 1)
		yeet->retcount += buffaddchar(yeet, c);
	if (yeet->flags != '-')
		yeet->retcount += buffaddchar(yeet, arg);
	return (0);
}
