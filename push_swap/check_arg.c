/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:13:37 by baura             #+#    #+#             */
/*   Updated: 2022/03/25 16:40:48 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* filling the stack */
void	find_dup(t_stack *stack)
{
	t_stack	*i;

	while (stack)
	{
		i = stack->next;
		while (i)
		{
			if (i->number == stack->number)
				error_message("Error\n");
			i = i->next;
		}
		stack = stack->next;
	}
}

void	check_arguments(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		if (arguments[i][j] == '\0')
			error_message("Error\n");
		if ((arguments[i][0] == '-' || arguments[i][0] == '+')
			&& ft_isdigit(arguments[i][1]))
			j++;
		while (arguments[i][j] != '\0')
		{
			if (!(ft_isdigit(arguments[i][j])))
				error_message("Error\n");
			j++;
		}
		i++;
	}
}

void	check_empty_arg(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		if (arguments[i][j] == '\0')
			error_message("Error\n");
		while (arguments[i][j] != '\0')
		{
			if (arguments[i][j] == ' ' && arguments[i][++j] == '\0')
				error_message("Error\n");
			if (arguments[i][j] == ' ')
				continue ;
			j++;
		}
		i++;
	}
}
