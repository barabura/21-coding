/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:02:07 by baura             #+#    #+#             */
/*   Updated: 2022/03/25 16:01:55 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = stacklast(*stack);
	if (last)
		last->next = new;
	else
		*stack = new;
}

t_stack	*stacknew(int content, int index)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (new_elem == NULL)
		return (NULL);
	new_elem->number = content;
	new_elem->index = index;
	new_elem->next = NULL;
	return (new_elem);
}

void	create_stack(t_content *content, char **argv)
{
	int		index;
	int		i;
	int		j;
	char	**spl_arg;
	t_stack	*tmp;

	i = 1;
	index = 1;
	while (argv[i])
	{
		spl_arg = ft_split(argv[i++], ' ');
		check_arguments(spl_arg);
		j = 0;
		while (spl_arg[j])
		{
			tmp = stacknew(atoi_ps(spl_arg[j++]), index++);
			stackadd_back(&(content->a), tmp);
			find_dup(tmp);
		}
		ft_free_array(spl_arg, j);
	}
	sort_index(content->a);
}
