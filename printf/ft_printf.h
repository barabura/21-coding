/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:50:53 by baura             #+#    #+#             */
/*   Updated: 2021/11/16 18:22:29 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_pointer(void *p);
int	ft_putnbr(int n);
int	ft_un_nbr(unsigned int n);
int	ft_dec_to_hex(unsigned int n);
int	ft_dec_to_up_hex(unsigned int n);

#endif
