/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:26:58 by ooussaad          #+#    #+#             */
/*   Updated: 2022/12/18 21:28:44 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		fout;

	fout = open(argv[1], O_RDONLY, 0777);
	if (fout == -1)
		error();
 	dup2(fd[1], 0);
 	dup2(fout, 1);
 	close(fd[0]);
 	excute_cmd1((char **)argv[2], envp);
}



int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
	}
}
