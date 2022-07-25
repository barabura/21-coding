/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:25:26 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 13:53:10 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_content *data, t_stack *stack)
{
	t_stack	*min;

	min = stack_min_index(stack);
	if (stack == min)
		do_rotate(data, stack);
	else if (stack != min && stack != stack_max_index(stack))
		do_reverse(data, stack);
	else if (stack->next == min)
		do_rotate(data, stack);
	else
		do_swap(data, stack);
}

void	small_sort(t_content *data)
{
	int	count;

	while (!check_sort_stack(data->a))
	{
		count = stacksize(data->a);
		if (count == 2)
			do_rotate(data, data->a);
		else if (count == 3)
			sort_three(data, data->a);
		else
			ft_push_top(data, data->a, stack_min_index(data->a));
	}
	while (data->b)
		ft_push_top(data, data->b, stack_index(data->b, data->a->index - 1));
}
