/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:40:50 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/18 18:00:24 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	char *tester = "Valeur : %-*.*s =)\\";
	unsigned int		arg1 = 2147364;
	char *				arg2 = "okboomer";
	char *ok = &arg1;

	int ret2 = printf("FT_Printf : %.*s is %c test numero %u de valeur entre %*.*d et %i soit (%x et %X) avec 100%% de reussite [%p]",2, "test", 'a', 10,15,5, 21, 42, 16, 42, ok);
	printf("|--\n");
	int ret = ft_printf("FT_Printf : %.*s is %c test numero %u de valeur entre %*.*d et %i soit (%x et %X) avec 100%% de reussite [%p]",2, "test", 'a', 10,15,5, 21, 42, 16, 42, ok);
	printf("|++\n");
	printf("[ft_printf = %d | ++] [printf = %d | --]\n", ret, ret2);
	// printf("|  %d++", printf("y4 R"));
	// printf("\n");
		// printf("|  %d--", ft_printf("y4 R"));
	// printf("\n");
	// printf("ydhW%8.0X%0xiR6TZgg", 0, -2147483647);
	// printf("\n");
	// ft_printf("ydhW%8.0X%0xiR6TZgg", 0, -2147483647);
	// printf("\n");
	return (0);
}