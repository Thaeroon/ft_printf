/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:06:13 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/23 19:08:22 by nicolas          ###   ########.fr       */
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
