/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:40:10 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/22 23:34:26 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_modif(t_modif **modif)
{
	(*modif)->attributes = 0;
	(*modif)->champ = -2;
	(*modif)->precision = -2;
	(*modif)->modif = 0;
	(*modif)->conv = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_modif		*modif;
	int			nb_wrote;

	if (!format)
		return (-1);
	nb_wrote = 0;
	va_start(ap, format);
	if (!(modif = (t_modif *)malloc(sizeof(t_modif))))
		exit (-1);
	while (*format)
	{
		nb_wrote += disp_until_mod(&format);
		if (*format)
		{
			init_modif(&modif);
			format = get_info(format, modif);
			disp_info(modif);
		}
	}
	free(modif);
	va_end(ap);
	return (nb_wrote);
}
