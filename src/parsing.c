/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:06:46 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/22 23:34:25 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int			get_attributes(char c)
{
	if (c == '#')
		return (1);
	if (c == '0')
		return (1<<1);
	if (c == '-')
		return (1<<2);
	if (c == '+')
		return (1<<3);
	if (c == ' ')
		return (1<<4);
	return (0);
}

int			get_champ(const char **str)
{
	int		nb;

	nb = 0;
	while ('0' <= **str && **str <= '9')
		nb = nb * 10 + (*(*str)++ - '0');
	if (**str == '*')
	{
		nb = -1;
		++(*str);
	}
	return (nb);
}

int			get_precision(const char **str)
{
	int		nb;

	nb = 0;
	while ('0' <= **str && **str <= '9')
		nb = nb * 10 + (*(*str)++ - '0');
	if (**str == '*')
	{
		nb = -1;
		++(*str);
	}
	return (nb);
}

int			get_modif(const char **str)
{
	if (**str == 'h')
	{
		if (**str && *(*str + 1) == 'h')
		{
			(*str)++;
			return (hh);
		}
		return (h);
	}
	if (**str == 'l')
	{
		if (**str && *(*str + 1) == 'l')
		{
			(*str)++;
			return (ll);
		}
		return (l);
	}
	if (*(*str + 1) == 'j')
		return (j);
	if (*(*str + 1) == 'z')
		return (j);
	return (none);
}

const char	*get_info(const char *str, t_modif *modif)
{
	while (*str && !ft_isalnum(*str) && *str != '.' && *str != '*')
		modif->attributes += get_attributes(*str++);
	modif->champ = get_champ(&str);
	if (*str == '.')
	{
		++str;
		modif->precision = get_precision(&str);
	}
	if ((modif->modif = get_modif(&str)))
		++str;
	modif->conv = *str;
	return ((*str) ? str + 1 : str);
}