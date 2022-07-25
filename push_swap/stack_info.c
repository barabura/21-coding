/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:21:19 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 14:21:27 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_first_part_stack(t_stack *stack, t_stack *n)
{
	t_stack	*middle;

	middle = middle_stack(stack);
	while (stack != middle)
	{
		if (stack == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_sort_data(t_content *data)
{
	t_stack	*tmp_a;

	tmp_a = data->a;
	if (data->b)
		return (0);
	while (tmp_a->next && tmp_a)
	{
		if (tmp_a->number > tmp_a->next->number)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}

int	check_sort_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*node_after_from_a(t_stack *a, t_stack *node)
{
	t_stack	*max;

	max = a;
	while (a)
	{
		if (a->index > node->index)
		{
			max = a;
			break ;
		}
		a = a->next;
	}
	while (a)
	{
		if (a->index > node->index && a->index < max->index)
			max = a;
		a = a->next;
	}
	return (max);
}
