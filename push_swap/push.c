/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:56:27 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 21:45:39 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;

	if (!stack_b)
		return ;
	p = *stack_b;
	*stack_b = (*stack_b)->next;
	p->next = *stack_a;
	*stack_a = p;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;

	if (!stack_a)
		return ;
	p = *stack_a;
	*stack_a = (*stack_a)->next;
	p->next = *stack_b;
	*stack_b = p;
}

void	do_push(t_content *content, t_stack *stack)
{
	if (stack == content->a)
	{
		push_a(&(content->a), &(content->b));
		do_com(content, "pa\n");
	}
	else
	{
		push_b(&(content->a), &(content->b));
		do_com(content, "pb\n");
	}
}

void	ft_push_top(t_content *content, t_stack *stack, t_stack *n)
{
	if (is_first_part_stack(stack, n))
		rotate_to_top(content, stack, n);
	else
		reverse_to_top(content, stack, n);
}
