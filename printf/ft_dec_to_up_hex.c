/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_up_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:29:51 by baura             #+#    #+#             */
/*   Updated: 2021/11/16 17:51:42 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
} */

static int	ft_nbrlen(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	ft_check_number(unsigned int n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		return (ft_putchar(c));
	}
	if (n == 10)
		return (ft_putchar('A'));
	if (n == 11)
		return (ft_putchar('B'));
	if (n == 12)
		return (ft_putchar('C'));
	if (n == 13)
		return (ft_putchar('D'));
	if (n == 14)
		return (ft_putchar('E'));
	if (n == 15)
		return (ft_putchar('F'));
	return (0);
}

int	ft_dec_to_up_hex(unsigned int n)
{
	unsigned int	i;
	unsigned int	nb;

	nb = n;
	if (n < 16)
	{
		ft_check_number(n);
	}
	if (n >= 16)
	{
		i = n % 16;
		n = ft_dec_to_up_hex(n / 16);
		ft_check_number(i);
	}
	return (ft_nbrlen(nb));
}

/* int	main(void)
{
	unsigned int numb = 567899;
	ft_dectohex(numb);
	return (0);
} */
