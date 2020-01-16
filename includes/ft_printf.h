/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:38:11 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/16 11:28:38 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>
# define B_SIZE 4096

int				ft_printf(const char *str, ...);

typedef	struct	s_struct
{
	char		buff[B_SIZE];
	char		*str;
	int			index;
	int			retcount;
	int			flags;
	int			width;
	int			precision;
	// int			size;
	int			type;
	va_list		ap;
}				t_struct;

int				buffaddchar(t_struct *yeet, char c);
int				buffaddstr(t_struct *yeet, char *str);
int				ft_parsing(t_struct *yeet, va_list ap);
int				ft_getflags(t_struct *yeet, va_list ap);
int				ft_checkchar(const char c);

#endif
