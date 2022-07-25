/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:56:33 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 21:39:07 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

/* the structure for stacks */
typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}				t_stack;

/* the structure for stacks content */
typedef struct s_content
{
	t_stack	*a;
	t_stack	*b;
	int		counter;
}				t_content;

/* the structure for sorting */
typedef struct s_sort
{
	int	a;
	int	b;
	int	min_comb;
}				t_sort;

/* push_swap utils */
int		stacksize(t_stack *stack);
void	error_message(char *str);
void	ft_putstr(char *s);
long	atoi_ps(const char *str);
void	do_com(t_content *data, char *com);

/* stack creation */
void	create_stack(t_content *content, char **argv);
t_stack	*stacklast(t_stack *lst);

/* indexes sorting */
void	sort_index(t_stack *stack);
t_stack	*stack_index(t_stack *stack, int index);

/* index utils */
t_stack	*stack_min_index(t_stack *stack);
t_stack	*stack_max_index(t_stack *stack);
t_stack	*middle_index_stack(t_stack *stack);
t_stack	*middle_stack(t_stack *stack);

/* check arguments */
void	find_dup(t_stack *stack);
void	check_arguments(char **arguments);
void	check_empty_arg(char **arguments);

/* Push operations */
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	do_push(t_content *content, t_stack *stack);
void	ft_push_top(t_content *content, t_stack *stack, t_stack *n);

/* Swap operations */
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap(t_stack **stack_a, t_stack **stack_b);
void	do_swap(t_content *data, t_stack *stack);

/* Rotate operations */
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate(t_stack **stack_a, t_stack **stack_b);
void	do_rotate(t_content *data, t_stack *stack);
void	rotate_to_top(t_content *content, t_stack *top, t_stack *stack);

/* Reverse rotate operations */
void	rev_rotate_a(t_stack **stack);
void	rev_rotate_b(t_stack **stack);
void	rev_rotate(t_stack **stack_a, t_stack **stack_b);
void	do_reverse(t_content *content, t_stack *stack);
void	reverse_to_top(t_content *content, t_stack *top, t_stack *stack);

/* check content order */
int		stack_ordered(t_stack *stack);
int		stack_sorted(t_stack *stack_a, t_stack *stack_b);
int		check_sort_data(t_content *data);
int		check_sort_stack(t_stack *stack);

/* stack sorting */
void	small_sort(t_content *data);
void	big_sort(t_content *data);

/* stack info */
t_stack	*node_after_from_a(t_stack *a, t_stack *node);
int		is_first_part_stack(t_stack *stack, t_stack *n);
t_stack	*node_which_min_com(t_content *data, t_sort *rotate);

/* compare operations */
int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

/* clear stack */
void	free_both(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);

#endif
