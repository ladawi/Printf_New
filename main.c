/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:40:50 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 17:50:29 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	printf("  %d++", printf("Valeur : %0-10c \\", 42));
	printf("\n");
	printf("  %d--", ft_printf("Valeur : %10c \\", 42));
	printf("\n");
	return (0);
}