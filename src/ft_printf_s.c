/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:13:43 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/17 20:08:42 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 		ft_printf_s(t_struct *yeet, char *arg)
{
	char	c;
	int		size;

	if (arg == NULL)
		arg = "(null)";
	if (yeet->precision != 0)
		size = (yeet->precision > ft_strlen(arg)) ? ft_strlen(arg) : yeet->precision;
	else
		size = ft_strlen(arg);
	c = (yeet->flags == '0') ? '0' : ' ';
	if (yeet->flags == '-')
		yeet->retcount += buffaddstr(yeet, arg, size);
	while (yeet->width-- > size)
		yeet->retcount+= buffaddchar(yeet, c);
	if (yeet->flags != '-'){
		yeet->retcount += buffaddstr(yeet, arg, size);}
	return (0);
}