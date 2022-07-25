/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:56:23 by baura             #+#    #+#             */
/*   Updated: 2022/03/24 14:34:53 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_content	content;

	if (argc == 1)
		return (1);
	content.a = NULL;
	content.b = NULL;
	content.counter = 0;
	check_empty_arg(argv);
	create_stack(&content, argv);
	if (content.a == NULL)
		return (1);
	find_dup(content.a);
	if (stack_ordered(content.a) == 1)
	{
		if (stacksize(content.a) < 6)
			small_sort(&content);
		else
			big_sort(&content);
	}
	free_both(&content.a, &content.b);
	return (0);
}
