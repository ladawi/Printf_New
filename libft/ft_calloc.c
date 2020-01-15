/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:15:40 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/18 14:36:40 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	int			len;

	len = count * size;
	len ? len : len++;
	if (!(ptr = (void*)malloc(len)))
		return (0);
	ft_bzero(ptr, len);
	return (ptr);
}
