/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2017/03/08 16:53:33 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		nb_wrote;
	char	*str1 = "%u";
	char	*str2 = "%llu";

	long long int	arg1 = -42;

	nb_wrote = ft_printf(str1, arg1);
	printf("|<- %i\n", nb_wrote);
	while (nb_wrote-- > 0)
		printf("^");
	printf("\n");
	printf("|<- %i", printf(str1, arg1));
	printf("\n\n");

	nb_wrote = ft_printf(str2, arg1);
	printf("|<- %i\n", nb_wrote);
	while (nb_wrote-- > 0)
		printf("^");
	printf("\n");
	printf("|<- %i", printf(str2, arg1));
	printf("\n");



	(void)argv;
	(void)arg1;
	(void)nb_wrote;
	(void)argc;
	return (0);
}
