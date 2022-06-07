/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:06:45 by baura             #+#    #+#             */
/*   Updated: 2022/03/13 14:19:28 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void	error_message(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}


int	main(int argc, char **argv, char **envp)
{
	

	if (argc < 5)
		error_message("Wrong number of arguments");
	



	
}


/* int main(int argc, char **argv, char **envp)
{
	int		fd[3][2];
	int		i;
	pid_t	pid1;
	pid_t	pid2;
	pid_t	pid3;
	int		file;

	i = 0;
	while (i < 3)
	{
		if (pipe(fd[i]) < 0)
			error_message("An error with opening a pipe");
		// нужно учесть случай в котором 1 или 2 пайпа открылись, а 3 уже смешарик
		i++;
	}
	pid1 = fork();
	if (pid1 < 0)
		error_message("An error with fork 1");
	if (pid1 == 0)
	{
		// child process 1
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][1]);
		close(fd[2][0]);
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			error_message("Open error in the child 1");

		
			
		
	}
	
	

	return (0);
} */