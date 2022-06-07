/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:41:59 by baura             #+#    #+#             */
/*   Updated: 2022/03/05 19:20:33 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **argv, char **envp, int *end)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		error_message("Open error in the child 1");
	if (close(end[0]) == -1)
		error_message("Close error 1 in the child 1");
	if (dup2(file, STDIN_FILENO) == -1)
		error_message("Dup2 error 1 in the child 1");
	if (dup2(end[1], STDOUT_FILENO) == -1)
		error_message("Dup2 error 2 in the child 1");
	if (close(end[1]) == -1)
		error_message("Close error 2 in the child 1");
	cmd_exec(argv[2], envp);
}

void	child2(char **argv, char **envp, int *end)
{
	int	file;

	file = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file == -1)
		error_message("Open error in the child 2");
	if (close(end[1]) == -1)
		error_message("Close error 1 in the child 2");
	if (dup2(file, STDOUT_FILENO) == -1)
		error_message("Dup2 error 1 in the child 2");
	if (dup2(end[0], STDIN_FILENO) == -1)
		error_message("Dup2 error 2 in the child 2");
	if (close(end[0]) == -1)
		error_message("Close error 2 in the child 2");
	cmd_exec(argv[3], envp);
}

void	forks(char **argv, char **envp, int *end)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		error_message("An error with fork 1");
	if (pid1 == 0)
		child1(argv, envp, end);
	pid2 = fork();
	if (pid2 < 0)
		error_message("An error with fork 2");
	if (pid2 == 0)
		child2(argv, envp, end);
	if (close(end[0]) == -1)
		error_message("Close error end[0]");
	if (close(end[1]) == -1)
		error_message("Close error end[1]");
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];

	if (argc != 5)
		error_message("Wrong number of arguments");
	if (pipe(end) == -1)
		error_message("An error with openning a pipe");
	forks(argv, envp, end);
	return (0);
}
