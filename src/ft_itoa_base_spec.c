/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:05:41 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/25 01:35:05 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(intmax_t n, int base)
{
	int		len;

	len = (n < 0);
	while (n != 0)
	{
		n /= base;
		++len;
	}
	return (len);
}

static void	ft_reverse(char *str, int len)
{
    int		start;
    int		end;
	char	tmp;

	start = -1;
	end = len;
    while (++start < --end)
    {
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
    }
}

static void	ft_appendnb(char *str, intmax_t nb, int base, int mod)
{
	int		tmp;

	while (nb != 0)
	{
		tmp = nb % base;
		*str++ = (tmp > 9) ? (tmp - 10) + mod : tmp + '0';
		nb /= base;
	}
}

char		*ft_itoa_base_spec(intmax_t nb, int base, int mod)
{
	char	*str;
    int		isneg;
	int		len;

    if (nb == 0)
        return (ft_strdup("0"));
	len = ft_intlen(nb, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		exit (-3);
	isneg = 0;
    if (nb < 0 && base == 10)
    {
        isneg = 1;
        nb = -nb;
    }
    ft_appendnb(str, nb, base, mod);
    if (isneg)
        str[len++] = '-';
    str[len] = '\0';
    ft_reverse(str, len);
    return (str);
}
