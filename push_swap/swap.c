/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:22:16 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 21:45:08 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack	*p;

	if (stack == NULL)
		return ;
	if (stacksize(*stack) > 1)
	{
		p = *stack;
		*stack = (*stack)->next;
		p->next = (*stack)->next;
		(*stack)->next = p;
	}
}

void	swap_b(t_stack **stack)
{
	t_stack	*p;

	if (stack == NULL)
		return ;
	if (stacksize(*stack) > 1)
	{
		p = *stack;
		*stack = (*stack)->next;
		p->next = (*stack)->next;
		(*stack)->next = p;
	}
}

void	swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;

	if (stack_a == NULL)
		return ;
	if (stacksize(*stack_a) > 1)
	{
		p = *stack_a;
		*stack_a = (*stack_a)->next;
		p->next = (*stack_a)->next;
		(*stack_a)->next = p;
	}
	if (stack_b == NULL)
		return ;
	if (stacksize(*stack_b) > 1)
	{
		p = *stack_b;
		*stack_b = (*stack_b)->next;
		p->next = (*stack_b)->next;
		(*stack_b)->next = p;
	}
}

void	do_swap(t_content *data, t_stack *stack)
{
	if (stack == data->a)
	{
		swap_a(&(data->a));
		do_com(data, "sa\n");
	}
	else if (stack == data->b)
	{
		swap_b(&(data->b));
		do_com(data, "sb\n");
	}
	else
	{
		swap(&(data->a), &(data->a));
		do_com(data, "ss\n");
	}
}
