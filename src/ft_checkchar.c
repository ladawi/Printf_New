/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:27:49 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 11:32:04 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_checkchar(const char c)
{
	int		i;
	int		j;
	char	*tab;

	tab = "cdiuxXsp%";
	i = 0;
	j = 0;
	while (tab[j])
	{
		if (tab[j] == c)
		{
			i++;
		}
		j++;
	}
	return (i);
}
