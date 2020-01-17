/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:18:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/17 21:03:50 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

int		ft_parsing(t_struct *yeet, va_list ap)
{
	int		i;
	
	i = 0;
	// printf("[type = %c]\n", yeet->type);
	if(yeet->type == 'c')
	{
		ft_printf_c(yeet, va_arg(ap, int));
	}
	else if(yeet->type == 'd')
	{
		ft_printf_d(yeet, va_arg(ap, int));
	}
	else if(yeet->type == 'i')
	{
		ft_printf_d(yeet, va_arg(ap, int));
	}
	else if(yeet->type == 'u')
	{
		ft_printf_u(yeet, va_arg(ap, unsigned int));
	}
	else if(yeet->type == 'x')
	{
		ft_printf_x(yeet, va_arg(ap, int));
	}
	else if(yeet->type == 'X')
	{
		ft_printf_x(yeet, va_arg(ap, int));
	}
	else if(yeet->type == 's')
	{
		ft_printf_s(yeet, va_arg(ap, char *));
	}
	else if(yeet->type == 'p')
	{
		// ft_printf_p(yeet, va_arg(ap, int));
		printf("prout\n");
	}
	else if(yeet->type == '%')
	{
		ft_printf_c(yeet, '%');
	}
	yeet->strid++; // remove 'type'
	return (0);
}