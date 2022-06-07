/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:35:33 by baura             #+#    #+#             */
/*   Updated: 2021/11/19 16:55:24 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_un_nbr(unsigned int n)
{
	unsigned int	nb;
	unsigned int	i;
	char			c;

	nb = n;
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	if (nb >= 10)
	{
		i = nb % 10;
		nb = ft_un_nbr(nb / 10);
		c = i + '0';
		write (1, &c, 1);
	}
	return (ft_nbrlen(n));
}

/* int	main(void)
{
	unsigned int	n = -2147483647;
	printf("\n%d", ft_un_nbr(n));
	printf("\n%u", n);
	return (0);
} */
