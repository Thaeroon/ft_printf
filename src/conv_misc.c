/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:51:08 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/25 01:19:34 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_s(t_modif *modif, va_list arg)
{
	char	*str;
	char	*ret;
	int		str_len;
	int		cpt;

	if (modif->modif == l)
		return (conv_S(modif, arg));
	str = (char*)va_arg(arg, char*);
	if (modif->precision == -2)
		str_len = ft_strlen(str);
	else
		str_len = modif->precision;
	if (!(ret = (char*)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	cpt = 0;
	while (cpt < str_len)
	{
		ret[cpt] = str[cpt];
		++cpt;
	}
	ret[cpt] = '\0';
	return (ret);
}

static int		get_size(wchar_t *str, int precision)
{
	int		str_len;
	int		cpt;
	char	tmp[5];

	str_len = 0;
	cpt = -1;
	if (precision != -2)
		while (++cpt < precision)
			str_len += wchar_tochar(tmp, str[cpt]);
	else
		while (str[++cpt])
			str_len += wchar_tochar(tmp, str[cpt]);
	return (str_len);
}

char	*conv_S(t_modif *modif, va_list arg)
{
	wchar_t	*str;
	char	*ret;
	int		str_len;
	int		cpt_str;
	int		cpt_ret;

	str = (wchar_t*)va_arg(arg, wchar_t*);
	str_len = get_size(str, modif->precision);
	if (!(ret = (char*)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	cpt_str = 0;
	cpt_ret = 0;
	while (cpt_ret < str_len)
		cpt_ret += wchar_tochar(ret + cpt_ret, str[cpt_str++]);
	ret[cpt_ret] = '\0';
	return (ret);
}

char	*conv_C(t_modif *modif, va_list arg)
{
	wchar_t		nb;
	char		*nb_str;
	char		tmp[5];
	(void)modif;
	nb = (wchar_t)va_arg(arg, wint_t);
	tmp[wchar_tochar(tmp, nb)] = '\0';
	nb_str = strdup(tmp);
	return (nb_str);
}

char	*conv_p(t_modif *modif, va_list arg)
{
	modif->attributes |= 1;
	return (conv_x(modif, arg));
}

char	*conv_mod(t_modif *modif, va_list arg)
{
	(void)modif;
	(void)arg;
	return (ft_strdup("%"));
}
