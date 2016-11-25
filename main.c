/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/25 04:56:24 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		nb_wrote;
	int		arg1;
	int		arg3;
	wchar_t	*arg2 = L"";

	(void)argc;
	char *str = "%5%";
	arg1 = 42;
	arg3 = 0;
	nb_wrote = ft_printf(str, arg1);
	printf("\n");
	while (nb_wrote-- > 0)
		printf("^");
	printf("\n");
	printf("\n%i", printf(str, arg1));
	printf("\n");
	(void)argv;
	(void)arg1;
	(void)arg2;
	(void)arg3;
	(void)nb_wrote;
	return (0);
}
