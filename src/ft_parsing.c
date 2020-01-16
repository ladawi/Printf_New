/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:18:18 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 17:05:10 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

int		ft_parsing(t_struct *yeet, va_list ap)
{
	int		i;
	
	i = 0;
	if(yeet->type == 'c')
	{
		ft_printf_c(yeet, ap);
	}
	else if(yeet->type == 'd')
	{
		printf("muk d\n");
	}
	else if(yeet->type == 'i')
	{
		printf("muk i\n");
	}
	else if(yeet->type == 'u')
	{
		printf("muk u\n");
	}
	else if(yeet->type == 'x')
	{
		printf("muk x\n");
	}
	else if(yeet->type == 'X')
	{
		printf("muk X\n");
	}
	else if(yeet->type == 's')
	{
		yeet->retcount += buffaddstr(yeet, va_arg(ap, char *));
	}
	else if(yeet->type == 'p')
	{
		printf("muk p\n");
	}
	else if(yeet->type == '%')
	{
		printf("muk %%\n");
	}
	yeet->strid++; // remove 'type'
	return (0);
}