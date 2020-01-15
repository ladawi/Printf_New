/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:44:00 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/18 16:59:38 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0)
		return (ft_strlen(src));
	if (ft_strlen(src) == size)
	{
		ft_memcpy(dst, src, size);
		dst[size - 1] = '\0';
	}
	if (ft_strlen(src) < size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	if (ft_strlen(src) > size)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}
