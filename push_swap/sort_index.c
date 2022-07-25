/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:28:52 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 14:35:23 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_index(t_stack *stack, int index)
{
	while (stack && stack->index != index)
		stack = stack->next;
	return (stack);
}

void	swap_index(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

void	sort_index(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		idx;

	i = stack;
	idx = 1;
	while (i && i->next)
	{
		j = stack;
		while (j)
		{
			if (j->index > idx && i->number > j->number)
			{
				swap_index(i, j);
				i = j;
			}
			j = j->next;
		}
		i = stack_index(stack, ++idx);
	}
}
