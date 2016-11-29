/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:29:43 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/29 20:23:55 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_i(t_modif *modif, va_list arg, int *arg_len)
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
		if (modif->att & 0x8)
			prefix = ft_strdup("+");
		else if (modif->att & 0x10)
			prefix = ft_strdup(" ");
	}
	else
		prefix = ft_strdup("-");
	if (prefix)
		nb_str = ft_strfjoin(&prefix, &nb_str, 3);
	*arg_len = ft_strlen(nb_str);
	return (nb_str);
}

char	*conv_o(t_modif *modif, va_list arg, int *arg_len)
{
	intmax_t	nb;
	char		*nb_str;
	char		*prefix;

	if (modif->precision == 0)
	{
		if (modif->att & 0x1)
		{
			*arg_len = 1;
			return (ft_strdup("0"));
		}
		else
			return (ft_strdup(""));
	}
	nb = get_unsigned_dec(modif, arg);
	nb_str = ft_itoa_base_spec(nb, 8, 0);
	nb_str = apply_dec_prec(modif, &nb_str);
	if (modif->att & 0x1 && *nb_str != '0')
	{
		prefix = ft_strdup("0");
		nb_str = ft_strfjoin(&prefix, &nb_str, 3);
	}
	*arg_len = ft_strlen(nb_str);
	return (nb_str);
}

char	*conv_u(t_modif *modif, va_list arg, int *arg_len)
{
	intmax_t	nb;
	char		*nb_str;

	nb = get_unsigned_dec(modif, arg);
	nb_str = ft_itoa_base_spec(nb, 10, 0);
	nb_str = apply_dec_prec(modif, &nb_str);
	*arg_len = ft_strlen(nb_str);
	return (nb_str);
}

char	*conv_x(t_modif *modif, va_list arg, int *arg_len)
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
	if (modif->att & 0x1 && *nb_str && *nb_str  != '0')
	{
		if (modif->conv == 'x')
			prefix = ft_strdup("0x");
		else
			prefix = ft_strdup("0X");
		nb_str = ft_strfjoin(&prefix, &nb_str, 3);
	}
	*arg_len = ft_strlen(nb_str);
	return (nb_str);
}

char	*conv_c(t_modif *modif, va_list arg, int *arg_len)
{
	char	ch;
	char	*ret;

	if (modif->modif == l)
		return (conv_C(modif, arg, arg_len));
	ch = (unsigned char)va_arg(arg, int);
	if (!(ret = (char*)malloc(sizeof(char) * 2)))
		return (0);
	ret[0] = ch;
	ret[2] = '\0';
	*arg_len = 1;
	return (ret);
}
