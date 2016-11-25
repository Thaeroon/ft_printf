/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:06:13 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/24 22:42:22 by nicolas          ###   ########.fr       */
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

	i = 0;
	len = ft_strlen(*nb_str);
	zero = modif->precision - len;
	if (zero <= 0)
		return (*nb_str);
	if (!(tmp = (char *)malloc(sizeof(char) * (zero + 1))))
		exit (-3);
	while (zero--)
		tmp[i++] = '0';
	tmp[i] = '\0';
	return (ft_strfjoin(&tmp, nb_str, 3));
}

char		*apply_champ(char **arg, int size, int isneg, char type)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		exit (-3);
	if (isneg)
		type = ' ';
	while (size--)
		tmp[i++] = type;
	tmp[i] = '\0';
	if (isneg)
		return (ft_strfjoin(arg, &tmp, 3));
	else
		return (ft_strfjoin(&tmp, arg, 3));
}

int			wchar_tochar(char *dest, wchar_t ch)
{
    if (ch <= 0x7F) {
        dest[0] = (char)ch;
        return 1;
    }
    if (ch <= 0x7FF) {
        dest[0] = (ch>>6) | 0xC0;
        dest[1] = (ch & 0x3F) | 0x80;
        return 2;
    }
    if (ch <= 0xFFFF) {
        dest[0] = (ch>>12) | 0xE0;
        dest[1] = ((ch>>6) & 0x3F) | 0x80;
        dest[2] = (ch & 0x3F) | 0x80;
        return 3;
    }
    if (ch <= 0x10FFFF) {
        dest[0] = (ch>>18) | 0xF0;
        dest[1] = ((ch>>12) & 0x3F) | 0x80;
        dest[2] = ((ch>>6) & 0x3F) | 0x80;
        dest[3] = (ch & 0x3F) | 0x80;
        return 4;
    }
    return 0;
}
