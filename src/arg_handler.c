/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:42:30 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/23 19:59:52 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fun(char *(*tf[123])(t_modif *, va_list))
{
	int		i;

	i = 0;
	while (i < 123)
		tf[i++] = 0;
	tf['s'] = &conv_s;
	tf['S'] = &conv_s;
	tf['p'] = &conv_p;
	tf['d'] = &conv_i;
	tf['D'] = &conv_i;
	tf['i'] = &conv_i;
	tf['o'] = &conv_o;
	tf['O'] = &conv_o;
	tf['u'] = &conv_u;
	tf['U'] = &conv_u;
	tf['x'] = &conv_x;
	tf['X'] = &conv_x;
	tf['c'] = &conv_c;
	tf['C'] = &conv_c;
	tf['%'] = &conv_mod;
}

char	*get_fun(t_modif *info, va_list ap)
{
	char	*(*tf[123])(t_modif *, va_list);

	init_fun(tf);
	if (tf[(int)info->conv] == 0)
		return (NULL);
	return (tf[(int)info->conv](info, ap));
}

void	put_arg(t_modif *modif, char **ret_str, int	*ret_len, va_list ap)
{
	char	*arg;

	if ((arg = get_fun(modif, ap)))
		*ret_len += copy_arg(ret_str, *ret_len, arg, ft_strlen(arg));
	free(arg);
}
