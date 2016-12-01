/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2016/12/01 15:45:24 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		nb_wrote;
	int		arg1;
	uintmax_t		arg3;
	char	*arg2 = "42";

	(void)argc;
	char *str = "%#08x";
	arg1 = 42;
	arg3 = 0;
	nb_wrote = ft_printf(str, arg1);
	printf("|<- %i\n", nb_wrote);
	while (nb_wrote-- > 0)
		printf("^");
	printf("\n");
	printf("|<- %i", printf(str, arg1));
	printf("\n");
	(void)argv;
	(void)arg1;
	(void)arg2;
	(void)arg3;
	(void)nb_wrote;
	return (0);
}
