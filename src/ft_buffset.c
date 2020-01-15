/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:56:28 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/15 20:55:06 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		buffaddchar(t_struct *yeet, char c)
{
	if (yeet->index < B_SIZE)
		yeet->buff[yeet->index] = c;
	else
	{
		write(1, yeet->buff, yeet->index);
		ft_memset(yeet->buff, 0, B_SIZE);
		yeet->index = 0;
	}
	yeet->index++;
	return (1);
}

int		buffaddstr(t_struct *yeet, char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (yeet->index >= B_SIZE)
		{
			write(1, yeet->buff, B_SIZE);
			ft_memset(yeet->buff, 0, B_SIZE);
			yeet->index = 0;
		}
		yeet->buff[yeet->index] = str[i];
		i++;
		yeet->index++;
	}
	return (i);
}
