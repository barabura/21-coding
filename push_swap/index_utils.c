/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:57:19 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 13:13:30 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_min_index(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	if (stack)
	{
		while (stack)
		{
			if (stack->index < min->index)
				min = stack;
			stack = stack->next;
		}
	}
	return (min);
}

t_stack	*stack_max_index(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	if (stack)
	{
		while (stack)
		{
			if (stack->index > max->index)
				max = stack;
			stack = stack->next;
		}
	}
	return (max);
}

t_stack	*middle_stack(t_stack *stack)
{
	int	count;
	int	i;

	count = stacksize(stack);
	i = 1;
	while (i++ != count / 2 + 1)
		stack = stack->next;
	return (stack);
}

t_stack	*middle_index_stack(t_stack *stack)
{
	int		i;
	int		j;
	int		size;
	t_stack	*tmp;

	i = stack_min_index(stack)->index;
	j = stack_max_index(stack)->index;
	size = stacksize(stack) / 2 + 1;
	tmp = stack_index(stack, i);
	while (size)
	{
		tmp = stack_index(stack, ++i);
		if (tmp)
			size--;
	}
	return (tmp);
}
