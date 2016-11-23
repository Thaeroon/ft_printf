/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:05:19 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/23 18:32:34 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		copy_until_mod(const char **str, char **ret, int ret_len)
{
	int		str_len;
	char	*tmp;
	int		index;

	str_len = 0;
	while ((*str)[str_len] != '%' && (*str)[str_len])
		++str_len;
	if (!(tmp = (char *)malloc(sizeof(char) * (str_len + ret_len + 1))))
		exit (-2);
	index = 0;
	while (index < ret_len)
		tmp[index++] = *(*ret)++;
	while (index - ret_len < str_len)
		tmp[index++] = *(*str)++;
	tmp[index] = '\0';
	*ret -= ret_len;
	free(*ret);
	*ret = tmp;
	if (**str)
		(*str)++;
	return (str_len);
}

int		copy_arg(char **ret, int ret_len, char *arg, int arg_len)
{
	char	*tmp;
	int		index;

	if (!(tmp = (char *)malloc(sizeof(char) * (ret_len + arg_len + 1))))
		exit (-2);
	index = 0;
	while (index < ret_len)
		tmp[index++] = *(*ret)++;
	while (index - ret_len < arg_len)
		tmp[index++] = *arg++;
	tmp[index] = '\0';
	*ret -= ret_len;
	free(*ret);
	*ret = tmp;
	return (arg_len);
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
	printf("\n");
}
