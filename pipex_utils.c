/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:45:18 by ooussaad          #+#    #+#             */
/*   Updated: 2022/12/19 22:28:05 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

/*find path function*/
char	**find_path(char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (envp[i]) //first tape is searche for path // i use strnstr if not found path word she should be return 0
	{
		if (ft_strnstr(envp[i], "PATH=", 5) == 0)
			path = envp[i] + 5;
		i++;
	}
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i],"/");
		i++;
	}
	return (paths);
}

/* Function that take the command and send it to find_path
 before executing it. */
void excute_cmd1(char **argv,char **envp)
{
	int i = 0;
	char **cmd = ft_split (argv[2],' ');
	char **buf = find_path(envp);
	while (buf[i])
	{
		buf[i] = ft_strjoin(buf[i], cmd[0]);
			if (access(buf[i], X_OK) == 0)
				break;
			else
				error();
		i++;
	}
	if (execve(buf[i], cmd, envp) == -1)
		error();
	// execve(buf[i], cmd, envp);
}

void excute_cmd2(char **argv,char **envp)
{
	int i = 0;
	char **cmd = ft_split (argv[3],' ');
	char **buf = find_path(envp);
	while (buf[i])
	{
		buf[i] = ft_strjoin(buf[i], cmd[0]);
			if (access(buf[i], X_OK) == 0)
				break;
			else
				error();
		i++;
	}
	if (execve(buf[i], cmd, envp) == -1)
		error();
	//execve(buf[i], cmd, envp);
}

void error()
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}

