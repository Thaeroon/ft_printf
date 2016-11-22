/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:05:19 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/22 22:33:00 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		disp_until_mod(const char **str)
{
	int		len;

	len = 0;
	while ((*str)[len] != '%' && (*str)[len])
		++len;
	write(1, *str, len);
	*str = ((*str)[len]) ? (*str + len + 1) : (*str + len);
	return (len);
}

//a suppr
void	disp_info(t_modif *modif)
{
	printf("\n");
	printf("attributes :%d\n", modif->attributes);
	printf("champ      :%d\n", modif->champ);
	printf("precision  :%d\n", modif->precision);
	printf("modif      :%d\n", modif->modif);
	printf("conv       :%c\n", modif->conv);
}
