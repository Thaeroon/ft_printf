/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2017/03/20 19:23:02 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	int		nb_wrote;
	char	*str1 = "{%030x}";
	char	*str2 = "%llu";
	int i;
	int	arg1 = 0xFFFF;

	nb_wrote = ft_printf(str1, arg1);
	printf("|<- %i\n", nb_wrote);
	printf("|<- %i", printf(str1, arg1));
	printf("\n");



	(void)argv;
	(void)arg1;
	(void)nb_wrote;
	(void)argc;
	return (0);
}
