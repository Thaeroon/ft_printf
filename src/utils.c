/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:06:13 by nicolas           #+#    #+#             */
/*   Updated: 2017/03/09 14:47:35 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_signed_dec(t_modif *modif, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	if (modif->conv == 'D')
		nb = (long)nb;
	else if (modif->modif == hh)
		nb = (char)nb;
	else if (modif->modif == h)
		nb = (short int)nb;
	else if (modif->modif == l)
		nb = (long)nb;
	else if (modif->modif == ll)
		nb = (long long)nb;
	else if (modif->modif == z)
		nb = (size_t)nb;
	else if (modif->modif == none)
		nb = (int)nb;
	return (nb);
}

uintmax_t	get_unsigned_dec(t_modif *modif, va_list ap)
{
	uintmax_t	nb;

	nb = va_arg(ap, uintmax_t);
	if (modif->conv == 'U' || modif->conv == 'O')
		nb = (long)nb;
	else if (modif->modif == hh)
		nb = (unsigned char)nb;
	else if (modif->modif == h)
		nb = (unsigned short int)nb;
	else if (modif->modif == l)
		nb = (unsigned long)nb;
	else if (modif->modif == ll)
		nb = (unsigned long long)nb;
	else if (modif->modif == z)
		nb = (size_t)nb;
	else if (modif->modif == none)
		nb = (unsigned int)nb;
	return (nb);
}

char		*apply_dec_prec(t_modif *modif, char **nb_str)
{
	int		len;
	char	*tmp;
	int		i;
	int		zero;

	if (**nb_str == '0' && modif->precision == 0)
		return (ft_strdup(""));
	i = 0;
	len = ft_strlen(*nb_str);
	zero = modif->precision - len;
	if (zero <= 0)
		return (*nb_str);
	if (!(tmp = (char *)malloc(sizeof(char) * (zero + 1))))
		exit(-3);
	while (zero--)
		tmp[i++] = '0';
	tmp[i] = '\0';
	return (ft_strfjoin(&tmp, nb_str, 3));
}

char		*ap_champ(char **arg, int size, t_modif *modif,
						char type, int *arg_len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		exit(-3);
	while (size--)
		tmp[i++] = type;
	tmp[i] = '\0';
	*arg_len += i;
	if (modif->att & 0x4)
		return (ft_strfjoin(arg, &tmp, 3));
	if (modif->att & 0x2 && (modif->conv == 'i' || modif->conv == 'x'
			|| modif->conv == 'd' || modif->conv == 'D' || modif->conv == 'X'))
	{
		i = 0;
		while (((*arg)[i] < '0' || (*arg)[i] > '9')
				|| (*arg)[i + 1] == 'x' || (*arg)[i + 1] == 'X')
		{
			tmp[i] = (*arg)[i];
			(*arg)[i++] = '0';
		}
	}
	return (ft_strfjoin(&tmp, arg, 3));
}



int			wchar_tochar(char *dest, wchar_t ch)
{
	if (ch <= 0x7F)
	{
		dest[0] = (char)ch;
		return (1);
	}
	if (ch <= 0x7FF && MB_CUR_MAX > 1)
	{
		dest[0] = (ch >> 6) | 0xC0;
		dest[1] = (ch & 0x3F) | 0x80;
		return (2);
	}
	if (ch <= 0xFFFF && MB_CUR_MAX > 2)
	{
		dest[0] = (ch >> 12) | 0xE0;
		dest[1] = ((ch >> 6) & 0x3F) | 0x80;
		dest[2] = (ch & 0x3F) | 0x80;
		return (3);
	}
	if (ch <= 0x10FFFF && MB_CUR_MAX > 3)
	{
		dest[0] = (ch >> 18) | 0xF0;
		dest[1] = ((ch >> 12) & 0x3F) | 0x80;
		dest[2] = ((ch >> 6) & 0x3F) | 0x80;
		dest[3] = (ch & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}

/*
** a suppr
*/

void		affichebin(uintmax_t n)
{
	uintmax_t bit = 0;
	uintmax_t mask = 1;

	for (int i = 0; i < 64; ++i)
	{
		bit = (n & mask) >> i;
		printf("%jd", bit);
		mask <<= 1;
	}
	printf("\n");
}
