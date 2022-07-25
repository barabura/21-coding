/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:25:05 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 13:25:14 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_sort(t_content *data, t_stack *node_b)
{
	t_stack	*node_a;

	node_a = node_after_from_a(data->a, node_b);
	while (node_b != data->b || node_a != data->a)
	{
		if (node_b != data->b && node_a != data->a)
			do_rotate(data, NULL);
		else if (node_b != data->b)
			do_rotate(data, data->b);
		else if (node_a != data->a)
			do_rotate(data, data->a);
	}
	do_push(data, data->a);
}

void	reverse_sort(t_content *data, t_stack *node_b)
{
	t_stack	*node_a;

	node_a = node_after_from_a(data->a, node_b);
	while (node_b != data->b || node_a != data->a)
	{
		if (node_b != data->b && node_a != data->a)
			do_reverse(data, NULL);
		else if (node_b != data->b)
			do_reverse(data, data->b);
		else if (node_a != data->a)
			do_reverse(data, data->a);
	}
	do_push(data, data->a);
}

void	mix_sort(t_content *data, t_stack *node_b, t_sort *rotate)
{
	t_stack	*node_a;

	node_a = node_after_from_a(data->a, node_b);
	if (rotate->a)
		while (node_a != data->a)
			do_rotate(data, data->a);
	else
		while (node_a != data->a)
			do_reverse(data, data->a);
	if (rotate->b)
		while (node_b != data->b)
			do_rotate(data, data->b);
	else
		while (node_b != data->b)
			do_reverse(data, data->b);
	do_push(data, data->a);
}

void	sort_min_com(t_content *data)
{
	t_stack	*node;
	t_sort	rotate;

	rotate.a = 0;
	rotate.b = 0;
	while (data->b)
	{
		node = node_which_min_com(data, &rotate);
		if (rotate.a && rotate.b)
			rotate_sort(data, node);
		else if (!rotate.a && !rotate.b)
			reverse_sort(data, node);
		else
			mix_sort(data, node, &rotate);
	}
	node = stack_index(data->a, 1);
	if (!is_first_part_stack(data->a, node))
		while (!check_sort_data(data))
			do_reverse(data, data->a);
	else
		while (!check_sort_data(data))
			do_rotate(data, data->a);
}

void	big_sort(t_content *data)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*mid;
	int		count;

	count = stacksize(data->a);
	min = stack_min_index(data->a);
	max = stack_max_index(data->a);
	mid = middle_index_stack(data->a);
	while (count != 2)
	{
		if (data->a != min && data->a != max)
		{
			do_push(data, data->b);
			if (data->b->index > mid->index)
				do_rotate(data, data->b);
		}
		else
			do_rotate(data, data->a);
		count = stacksize(data->a);
	}
	sort_min_com(data);
}
