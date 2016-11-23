/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:51:08 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/23 20:02:14 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_s(t_modif *modif, va_list arg)
{
	(void)modif;
	(void)arg;
	return ("|s|");
}

char	*conv_p(t_modif *modif, va_list arg)
{
	(void)modif;
	(void)arg;
	return ("|p|");
}

char	*conv_c(t_modif *modif, va_list arg)
{
	(void)modif;
	(void)arg;
	return ("|c|");
}

char	*conv_mod(t_modif *modif, va_list arg)
{
	(void)modif;
	(void)arg;
	return (ft_strdup("%"));
}
