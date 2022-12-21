/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:45:18 by ooussaad          #+#    #+#             */
/*   Updated: 2022/12/20 21:29:13 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

/*find path function*/
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*road;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		road = ft_strjoin(path, cmd);
		if (access(road, F_OK) == 0)
			return road;
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (0);
}

/* Function that take the command and send it to find_path
 before executing it. */
void excute_cmd(char *argv,char **envp)
{
	int i = 0;
	char **cmd = ft_split (argv, ' ');
	char *buf = find_path(cmd[0], envp);
	if (!buf)
	{
		write (1, "no command found", 16);
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		exit(1);
	}
	execve(buf, cmd, envp);
}

void error()
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
    {
		write (1,str + i,1);
		i++;
	}
}

