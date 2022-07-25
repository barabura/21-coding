/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:53:59 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 22:30:06 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stack **stack)
{
	t_stack	*p;
	t_stack	*plast;

	if (!*stack || !(*stack)->next)
		return ;
	p = *stack;
	plast = p;
	while (plast->next->next)
		plast = plast->next;
	*stack = plast->next;
	(*stack)->next = p;
	plast->next = NULL;
}

void	rev_rotate_b(t_stack **stack)
{
	t_stack	*p;
	t_stack	*plast;

	if (!*stack || !(*stack)->next)
		return ;
	p = *stack;
	plast = p;
	while (plast->next->next)
		plast = plast->next;
	*stack = plast->next;
	(*stack)->next = p;
	plast->next = NULL;
}

void	rev_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	t_stack	*plast;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	p = *stack_a;
	plast = p;
	while (plast->next->next)
		plast = plast->next;
	*stack_a = plast->next;
	(*stack_a)->next = p;
	plast->next = NULL;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	p = *stack_b;
	plast = p;
	while (plast->next->next)
		plast = plast->next;
	*stack_b = plast->next;
	(*stack_b)->next = p;
	plast->next = NULL;
}

void	do_reverse(t_content *content, t_stack *stack)
{
	if (stack == content->a)
	{
		rev_rotate_a(&(content->a));
		do_com(content, "rra\n");
	}
	else if (stack == content->b)
	{
		rev_rotate_b(&(content->b));
		do_com(content, "rrb\n");
	}
	else
	{
		rev_rotate(&(content->a), &(content->b));
		do_com(content, "rrr\n");
	}
}

void	reverse_to_top(t_content *content, t_stack *top, t_stack *stack)
{
	if (content->a == top)
	{
		while (stack != content->a)
			do_reverse(content, content->a);
		do_push(content, content->b);
	}
	else if (content->b == top)
	{
		while (stack != content->b)
			do_reverse(content, content->b);
		do_push(content, content->a);
	}
}
