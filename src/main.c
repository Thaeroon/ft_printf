/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/22 22:55:11 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		nb_wrote;

	(void)argc;
	nb_wrote = ft_printf(argv[1], 5);
	printf("\naze%+5.lldaze", (long long int)5);
	printf("\n%d\n", nb_wrote);
	(void)argv;
	return (0);
}
