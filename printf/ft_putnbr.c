/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:35:20 by baura             #+#    #+#             */
/*   Updated: 2021/11/16 17:04:59 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int			i;
	char		c;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	if (nb >= 10)
	{
		i = nb % 10;
		nb = ft_putnbr(nb / 10);
		c = i + '0';
		write (1, &c, 1);
	}
	return (ft_nbrlen((long int)n));
}

/* int	main(void)
{
	int	n = -5;
	printf("\n%d", ft_putnbr(n));
	return (0);
} */
