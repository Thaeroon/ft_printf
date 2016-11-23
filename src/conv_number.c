/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:29:43 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/23 19:16:48 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_i(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;

	nb = get_signed_dec(modif, arg);
	nb_str = ft_itoa_base(nb, 10, 0);
	return (nb_str);
}

char	*conv_o(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;

	nb = get_unsigned_dec(modif, arg);
	nb_str = ft_itoa_base(nb, 8, 0);
	return (nb_str);
}

char	*conv_u(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;

	nb = get_unsigned_dec(modif, arg);
	nb_str = ft_itoa_base(nb, 10, 0);
	return (nb_str);
}

char	*conv_x(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;

	nb = get_unsigned_dec(modif, arg);
	if (modif->conv == 'x')
		nb_str = ft_itoa_base(nb, 16, 'a');
	else
		nb_str = ft_itoa_base(nb, 16, 'A');
	return (nb_str);
}
