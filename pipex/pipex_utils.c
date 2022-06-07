/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:47:17 by baura             #+#    #+#             */
/*   Updated: 2022/03/12 17:27:15 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free(paths);
	return (0);
}

void	cmd_exec(char *argv, char **envp)
{
	int		i;
	char	**cmd;
	char	*path;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (!access(cmd[0], F_OK))
		path = cmd[0];
	else
		path = find_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		while (cmd[i] != 0)
			free(cmd[i++]);
		free(cmd);
		error_message("Execve error");
	}
}
