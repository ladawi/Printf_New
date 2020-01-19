/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:38:11 by ladawi            #+#    #+#             */
/*   Updated: 2020/01/19 14:26:08 by ladawi           ###   ########.fr       */
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
	int			strid;
	int			index;
	int			retcount;
	int			lenprint;
	int			flags;
	int			width;
	int			precision;
	int			type;
	va_list		ap;
}				t_struct;

int				buffaddchar(t_struct *yeet, char c);
int				buffaddstr(t_struct *yeet, char *str, int size);
int				buffaddnbr(t_struct *yeet, long int nb, int size);
int				buffaddadress(t_struct *yeet, unsigned long int nb, int size);
int				ft_parsing(t_struct *yeet, va_list ap);
int				ft_scanstr(t_struct *yeet, va_list ap);
int				ft_getflags(t_struct *yeet, va_list ap);
int				ft_checkchar(const char c);
int				ft_printf_c(t_struct *yeet, int arg);
int				ft_printf_s(t_struct *yeet, char *arg);
int				ft_printf_d(t_struct *yeet, int arg);
int				ft_printf_u(t_struct *yeet, unsigned int arg);
int				ft_printf_x(t_struct *yeet, unsigned int arg);
int				ft_printf_p(t_struct *yeet, unsigned long int arg);

#endif
