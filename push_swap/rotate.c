/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:49:07 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 21:44:55 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack)
{
	t_stack	*p;
	t_stack	*last;

	if (!(*stack) && !((*stack)->next))
		return ;
	p = *stack;
	*stack = (*stack)->next;
	last = stacklast(p);
	last->next = p;
	p->next = NULL;
}

void	rotate_b(t_stack **stack)
{
	t_stack	*p;
	t_stack	*last;

	if (!(*stack) && !((*stack)->next))
		return ;
	p = *stack;
	*stack = (*stack)->next;
	last = stacklast(p);
	last->next = p;
	p->next = NULL;
}

void	rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		p = *stack_a;
		*stack_a = (*stack_a)->next;
		last = stacklast(p);
		last->next = p;
		p->next = NULL;
	}
	if (*stack_b && (*stack_b)->next)
	{
		p = *stack_b;
		*stack_b = (*stack_b)->next;
		last = stacklast(p);
		last->next = p;
		p->next = NULL;
	}
}

void	do_rotate(t_content *content, t_stack *stack)
{
	if (stack == content->a)
	{
		rotate_a(&(content->a));
		do_com(content, "ra\n");
	}
	else if (stack == content->b)
	{
		rotate_b(&(content->b));
		do_com(content, "rb\n");
	}
	else
	{
		rotate(&(content->a), &(content->b));
		do_com(content, "rr\n");
	}
}

void	rotate_to_top(t_content *content, t_stack *top, t_stack *stack)
{
	if (content->a == top)
	{
		while (stack != content->a)
			do_rotate(content, content->a);
		do_push(content, content->b);
	}
	else if (content->b == top)
	{
		while (stack != content->b)
			do_rotate(content, content->b);
		do_push(content, content->a);
	}
}
