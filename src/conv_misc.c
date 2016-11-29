/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:51:08 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/29 19:34:06 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_s(t_modif *modif, va_list arg, int *arg_len)
{
	char	*str;
	char	*ret;
	int		str_len;
	int		cpt;

	if (modif->modif == l)
		return (conv_S(modif, arg, arg_len));
	*arg_len = 6;
	if (!(str = (char*)va_arg(arg, char*)))
		return (ft_strdup("(null)"));
	if (modif->precision == -2)
		str_len = ft_strlen(str);
	else
		str_len = modif->precision;
	if (!(ret = (char*)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	cpt = 0;
	while (cpt < str_len && str[cpt])
	{
		ret[cpt] = str[cpt];
		++cpt;
	}
	ret[cpt] = '\0';
	*arg_len = cpt;
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
		while (str[++cpt]){
			str_len += wchar_tochar(tmp, str[cpt]);}
	return (str_len);
}

char	*conv_S(t_modif *modif, va_list arg, int *arg_len)
{
	wchar_t	*str;
	char	*ret;
	int		str_len;
	int		cpt_str;
	int		cpt_ret;

	*arg_len = 6;
	str = (wchar_t*)va_arg(arg, wchar_t*);
	if (!str)
		return (ft_strdup("(null)"));
	str_len = get_size(str, modif->precision);
	if (!(ret = (char*)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	cpt_str = 0;
	cpt_ret = 0;
	while (cpt_ret < str_len && str[cpt_str])
		cpt_ret += wchar_tochar(ret + cpt_ret, str[cpt_str++]);
	ret[cpt_ret] = '\0';
	*arg_len = cpt_ret;
	return (ret);
}

char	*conv_C(t_modif *modif, va_list arg, int *arg_len)
{
	wchar_t		nb;
	char		*nb_str;
	char		tmp[5];
	(void)modif;
	nb = (wchar_t)va_arg(arg, wint_t);
	tmp[wchar_tochar(tmp, nb)] = '\0';
	nb_str = ft_strdup(tmp);
	*arg_len = 1;
	return (nb_str);
}

char	*conv_p(t_modif *modif, va_list arg, int *arg_len)
{
	modif->att |= 1;
	return (conv_x(modif, arg, arg_len));
}

char	*conv_mod(t_modif *modif, va_list arg, int *arg_len)
{
	(void)modif;
	(void)arg;
	*arg_len = 1;
	return (ft_strdup("%"));
}
