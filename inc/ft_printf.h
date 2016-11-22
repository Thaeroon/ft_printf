/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:40:04 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/22 23:12:33 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

enum
{
	none, hh, h, l, ll, j, z
};

/*
** attributes : # 0 - + ' ' bitwise
** champ : si -2 non effectif si -1 next arg
** precision : si -2 non effectif si -1 next arg
** modif : si = 0 non effectif
*/

typedef struct	s_modif
{
	int		attributes;
	int		champ;
	int		precision;
	int		modif;
	char	conv;
}				t_modif;
const char	*get_info(const char *str, t_modif *modif);
int		ft_printf(const char *format, ...);
int		disp_until_mod(const char **str);
int		conv_s(t_modif *modif, va_list arg);
int		conv_p(t_modif *modif, va_list arg);
int		conv_d(t_modif *modif, va_list arg);
int		conv_i(t_modif *modif, va_list arg);
int		conv_o(t_modif *modif, va_list arg);
int		conv_u(t_modif *modif, va_list arg);
int		conv_x(t_modif *modif, va_list arg);
int		conv_c(t_modif *modif, va_list arg);

void	disp_info(t_modif *);

#endif
