/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:29:43 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/25 04:48:31 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_i(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;
	char		*prefix;

	prefix = NULL;
	nb = get_signed_dec(modif, arg);
	nb_str = ft_itoa_base_spec(nb, 10, 0);
	nb_str = apply_dec_prec(modif, &nb_str);
	if (nb >= 0)
	{
		if (modif->attributes & 0x8)
			prefix = ft_strdup("+");
		else if (modif->attributes & 0x10)
			prefix = ft_strdup(" ");
		if (prefix)
			nb_str = ft_strfjoin(&prefix, &nb_str, 3);
	}
	return (nb_str);
}

char	*conv_o(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;
	char		*prefix;

	if (modif->precision == 0)
		return (ft_strdup(""));
	nb = get_unsigned_dec(modif, arg);
	nb_str = ft_itoa_base_spec(nb, 8, 0);
	nb_str = apply_dec_prec(modif, &nb_str);
	if (modif->attributes & 0x1 && *nb_str != '0')
	{
		prefix = ft_strdup("0");
		nb_str = ft_strfjoin(&prefix, &nb_str, 3);
	}
	return (nb_str);
}

char	*conv_u(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;

	nb = get_unsigned_dec(modif, arg);
	nb_str = ft_itoa_base_spec(nb, 10, 0);
	nb_str = apply_dec_prec(modif, &nb_str);
	return (nb_str);
}

char	*conv_x(t_modif *modif, va_list arg)
{
	intmax_t	nb;
	char		*nb_str;
	char		*prefix;

	nb = get_unsigned_dec(modif, arg);
	if (modif->conv == 'x')
		nb_str = ft_itoa_base_spec(nb, 16, 'a');
	else
		nb_str = ft_itoa_base_spec(nb, 16, 'A');
	nb_str = apply_dec_prec(modif, &nb_str);
	if (modif->attributes & 0x1)
	{
		if (modif->conv == 'x')
			prefix = ft_strdup("0x");
		else
			prefix = ft_strdup("0X");
		nb_str = ft_strfjoin(&prefix, &nb_str, 3);
	}
	return (nb_str);
}

char	*conv_c(t_modif *modif, va_list arg)
{
	char	ch;
	char	*ret;

	if (modif->modif == l)
		return (conv_C(modif, arg));
	ch = (unsigned char)va_arg(arg, int);
	if (!(ret = (char*)malloc(sizeof(char) * 2)))
		return (0);
	ret[0] = ch;
	ret[2] = '\0';
	return (ret);
}
