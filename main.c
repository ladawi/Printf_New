/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:40:50 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 11:23:38 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	char *tester = "Valeur : %-10p =)\\";
	unsigned int		arg1 = 2147364;
	char *				arg2 = "okboomer";

	printf("  %d++", printf(tester, &arg1));
	printf("\n");
	printf("  %d--", ft_printf(tester, &arg1));
	printf("\n");

	return (0);
}