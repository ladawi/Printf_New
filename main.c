/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:40:50 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/17 21:15:59 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	char *tester = "Valeur : %p =)\\";
	unsigned int		arg1 = 2147364;
	char *				arg2 = "okboomer";

	printf("  %d++", printf(tester, arg2));
	printf("\n");
	printf("  %d--", ft_printf("Valeur : %x =)\\", arg2));
	printf("\n");

	return (0);
}