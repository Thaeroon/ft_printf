/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:42:30 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/22 17:29:14 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fun(int (*tf[123])(t_modif *, va_list))
{
	int		i;

	i = 0;
	while (i < 123)
		tf[i++] = 0;
	tf['s'] = &conv_s;
	tf['S'] = &conv_s;
	tf['p'] = &conv_p;
	tf['d'] = &conv_i;
	tf['D'] = &conv_d;
	tf['i'] = &conv_i;
	tf['o'] = &conv_o;
	tf['O'] = &conv_o;
	tf['u'] = &conv_u;
	tf['U'] = &conv_u;
	tf['x'] = &conv_x;
	tf['X'] = &conv_x;
	tf['c'] = &conv_c;
	tf['C'] = &conv_c;
}

int		get_fun(t_modif *info, va_list ap)
{
	int (*tf[123])(t_modif *, va_list);

	init_fun(tf);
	if (tf[(int)info->conv] == 0)
		return (0);
	return (tf[(int)info->conv](info, ap));
}
