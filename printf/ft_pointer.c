/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:06:38 by baura             #+#    #+#             */
/*   Updated: 2021/11/16 18:15:44 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned long int n)
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

static int	ft_check_number(unsigned long int n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		return (ft_putchar(c));
	}
	if (n == 10)
		return (ft_putchar('a'));
	if (n == 11)
		return (ft_putchar('b'));
	if (n == 12)
		return (ft_putchar('c'));
	if (n == 13)
		return (ft_putchar('d'));
	if (n == 14)
		return (ft_putchar('e'));
	if (n == 15)
		return (ft_putchar('f'));
	return (0);
}

static int	ft_nbr_conv(unsigned long int n)
{
	unsigned long int	i;
	unsigned long int	nb;

	nb = n;
	if (n < 16)
	{
		ft_check_number(n);
	}
	if (n >= 16)
	{
		i = n % 16;
		n = ft_nbr_conv(n / 16);
		ft_check_number(i);
	}
	return (ft_nbrlen(nb));
}

int	ft_pointer(void *p)
{
	write(1, "0x", 2);
	return (2 + ft_nbr_conv((unsigned long int)p));
}

/* int	main(void)
{
	char	c[] = "abc";
	ft_pointer(LONG_MAX);
	printf("\n%p", LONG_MAX);
	return (0);
} */
