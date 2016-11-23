/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:40:04 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/23 20:00:55 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

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

char		*ft_itoa_base(intmax_t nb, int base, int mod);
intmax_t	get_signed_dec(t_modif *modif, va_list ap);
uintmax_t	get_unsigned_dec(t_modif *modif, va_list ap);
int			copy_arg(char **ret, int ret_len, char *arg, int arg_len);
void		put_arg(t_modif *modif, char **ret_str, int	*ret_len, va_list ap);
const char	*get_info(const char *str, t_modif *modif);
int			ft_printf(const char *format, ...);
int			copy_until_mod(const char **str, char **ret, int ret_len);
char		*conv_s(t_modif *modif, va_list arg);
char		*conv_p(t_modif *modif, va_list arg);
char		*conv_i(t_modif *modif, va_list arg);
char		*conv_o(t_modif *modif, va_list arg);
char		*conv_u(t_modif *modif, va_list arg);
char		*conv_x(t_modif *modif, va_list arg);
char		*conv_c(t_modif *modif, va_list arg);
char		*conv_mod(t_modif *modif, va_list arg);

void		disp_info(t_modif *);

#endif
