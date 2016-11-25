/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/25 01:24:46 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		nb_wrote;
	int		arg1;
	char	*arg2 = "zeérçty";

	(void)argc;
	char *str="a%ib";
	nb_wrote = ft_printf(str, arg2);
	printf("\n");
	while (nb_wrote-- > 0)
		printf("^");
	printf("\n");
	printf("\n%i", printf(str, arg2));
	printf("\n");
	(void)argv;
	(void)arg1;
	(void)arg2;
	(void)nb_wrote;
	return (0);
}
