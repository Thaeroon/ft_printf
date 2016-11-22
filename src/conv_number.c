/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:29:43 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/22 17:41:32 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_d(t_modif *modif, va_list arg)
{
	int		nb_wrote;
	int		nb;

	nb_wrote = 0;
	nb = va_arg(arg, int);

	return (nb_wrote);
}
/*
int		conv_i(t_modif *modif, va_list arg)
{
	int		nb_wrote

	nb_wrote = 0;
	va_arg(arg, type);

	return (nb_wrote);
}

int		conv_o(t_modif *modif, va_list arg)
{
	int		nb_wrote

	nb_wrote = 0;
	va_arg(arg, type);

	return (nb_wrote);
}

int		conv_u(t_modif *modif, va_list arg)
{
	int		nb_wrote

	nb_wrote = 0;
	va_arg(arg, type);

	return (nb_wrote);
}
*/
