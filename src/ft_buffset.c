/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:56:28 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 17:48:20 by ladawi           ###   ########.fr       */
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
		buffaddchar(yeet, c);
		return (1);
	}
	yeet->index++;
	return (1);
}

int		buffaddstr(t_struct *yeet, char *str, int size)
{
	int		i;

	i = 0;
	size = (size == -1) ? ft_strlen(str) : size;
	while (str[i] != 0 && size-- > 0)
	{
		if (yeet->index < B_SIZE)
			yeet->buff[yeet->index] = str[i];
		else
		{
			write(1, yeet->buff, B_SIZE);
			ft_memset(yeet->buff, 0, B_SIZE);
			yeet->index = 0;
		}
		yeet->buff[yeet->index] = str[i];
		yeet->index++;
		i++;
	}
	return (i);
}

int		buffaddnbr(t_struct *yeet, long int nb, int size)
{
	int		i;
	char	*tmp;
	int		base;

	i = 0;
	base = (yeet->type == 'x' || yeet->type == 'X' || yeet->type == 'p')
		? 16 : 10;
		tmp = ft_itoa_base(nb, base);
	size = (size == -1) ? ft_strlen(tmp) : size;
	if (nb == 0 && yeet->precision == 0)
		return (0);
	while (tmp[i] != 0 && size-- > 0)
	{
		tmp[i] = (yeet->type == 'X') ? ft_toupper(tmp[i]) : tmp[i];
		if (yeet->index < B_SIZE)
			yeet->buff[yeet->index] = tmp[i];
		else
		{
			write(1, yeet->buff, B_SIZE);
			ft_memset(yeet->buff, 0, B_SIZE);
			yeet->index = 0;
		}
		yeet->buff[yeet->index++] = tmp[i++];
	}
	free(tmp);
	return (i);
}
