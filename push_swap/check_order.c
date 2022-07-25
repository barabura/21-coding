/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:25:07 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 13:52:33 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_ordered(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
		{
			if (stack->number > stack->next->number)
				return (1);
		}
		stack = stack->next;
	}
	return (0);
}

int	stack_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
		return (1);
	if (!stack_a)
		return (1);
	while (stack_a)
	{
		if (stack_a->next)
		{
			if (stack_a->number > stack_a->next->number)
				return (1);
		}
		stack_a = stack_a->next;
	}
	return (0);
}
