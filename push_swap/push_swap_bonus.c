/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:23:56 by baura             #+#    #+#             */
/*   Updated: 2022/03/25 15:24:56 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_com_gnl(t_content *data, char *com)
{
	if (!ft_strncmp(com, "ss\n", 4))
		swap(&data->a, &data->b);
	else if (!ft_strncmp(com, "sa\n", 4))
		swap_a(&data->a);
	else if (!ft_strncmp(com, "sb\n", 4))
		swap_b(&data->b);
	else if (!ft_strncmp(com, "pa\n", 4))
		push_a(&data->a, &data->b);
	else if (!ft_strncmp(com, "pb\n", 4))
		push_b(&data->a, &data->b);
	else if (!ft_strncmp(com, "ra\n", 4))
		rotate_a(&data->a);
	else if (!ft_strncmp(com, "rb\n", 4))
		rotate_b(&data->b);
	else if (!ft_strncmp(com, "rr\n", 4))
		rotate(&data->a, &data->b);
	else if (!ft_strncmp(com, "rra\n", 5))
		rev_rotate_a(&data->a);
	else if (!ft_strncmp(com, "rrb\n", 5))
		rev_rotate_b(&data->b);
	else if (!ft_strncmp(com, "rrr\n", 5))
		rev_rotate(&data->a, &data->b);
	else
		error_message("Error\n");
}

void	read_gnl(t_content *content)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		do_com_gnl(content, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_sort_data(content))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

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
	read_gnl(&content);
	free_both(&content.a, &content.b);
	return (0);
}
