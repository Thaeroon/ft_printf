/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/24 14:06:40 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		nb_wrote;

	(void)argc;
	char *str="aze% ixaze";
	nb_wrote = ft_printf(str, 0);
	printf("\n");
	while (nb_wrote-- > 0)
		printf("^");
	printf("\n");
	printf(str, 0);
	printf("\n");
	(void)argv;
	return (0);
}
