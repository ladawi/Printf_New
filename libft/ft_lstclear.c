/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:06:37 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/19 09:08:16 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && *lst)
	{
		if ((*lst)->next)
			ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
	}
	lst = NULL;
}
