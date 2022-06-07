/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:50:48 by baura             #+#    #+#             */
/*   Updated: 2021/11/16 17:55:15 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_symbol(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_un_nbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_dec_to_hex(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_dec_to_up_hex(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	j;
	size_t	i;

	va_start(args, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j += ft_check_symbol(format[i], args);
			i++;
		}
		else
		{
			write (1, &format[i], 1);
			i++;
			j++;
		}
	}
	va_end(args);
	return (j);
}

/* int main(void)
{
	// ft_printf("check for symbol: %c is here\n", 't');
	
	// ft_printf("check for string: %s is here\n", "test string");
	
	ft_printf("check for pointer: %p is here\n", );
	
	//ft_printf("check for number: %d is here\n", 56783);
	//ft_printf("check for integer: %i is here\n", -5600985);
	
	//ft_printf("check for unsigned number: %u is here\n", 28009003);
	
	char c[] = "abc";
	printf ("%lu\n", c);
	ft_printf("check for l-hexadecimal number: %p is here\n", c);
	printf("%u\n", 140732802803864);
	
	//ft_printf("check for u-hexadecimal number:: %X is here\n", );
	
	// ft_printf("check for percent sign: %% is here\n");
	return (0);
} */

/* 
printf("orig %d", printf("%lx\n", 4294967295));

c = va_arg(args, int);
s = va_arg(args, char *);
d = va_arg(args, int);
i = va_arg(args, int);
u = va_arg(args, unsigned int);
p = va_arg(args, unsigned long);
x = va_arg(args, unsigned int);
X = va_arg(args, unsigned int); */

/* #include <stdio.h>
void var(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(!strcmp(format, "%d"))
	{
		int x = va_arg (ap, int);
		printf ("You passed decimal object with value %d\n", x);
	}

	if(!strcmp(format, "%s"))
	{
		char *p = va_arg (ap, char *);
		printf ("You passed c-string \"%s\"\n", p);
	}
	va_end (ap);
}
int main(int argc, char const *argv[])
{
	printf("%d", "asdasd");
	return 0;
} */