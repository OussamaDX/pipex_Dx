/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:26:58 by ooussaad          #+#    #+#             */
/*   Updated: 2022/12/21 22:36:56 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		fin;
	if (access(argv[1], F_OK) == - 1) //if cmd 1 not found
	{
		write(2, "no such file or directory", 20);
		exit(1);
	}
	fin = open(argv[1], O_RDONLY, 0777); // we should open a file and read it
	dup2(fd[1], 1); // ||1 = output ||
	dup2(fin, 0); // ||0 = input  ||
	close(fd[0]);
	excute_cmd(argv[2], envp);
}

void parent_process(char **argv, char **envp,int *fd)
{
	int fout2;
	fout2 = open(argv[4], O_CREAT | O_RDWR, 0777);
	if (fout2 == -1)
    {
		write(1, "no file or directory", 20);
	}
	dup2(fd[0], 0);
	dup2(fout2, 1);
	close(fd[1]);
	excute_cmd(argv[3] ,envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int	pid1;
	int pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			write (1, "no piping", 9);
			return (0);
		}
		pid1 = fork();
		if (pid1 == -1)
		{
			write(1, "no child", 8);
		}
		if (pid1 == 0)
			child_process(argv, envp, fd);
		else
		{
			pid2 = fork();
			if (pid2 == -1)
            {
				write(2, "no child", 8);
			}
			if (pid2 == 0)
                parent_process(argv, envp, fd);
			else
				waitpid(pid1, NULL, 0);
		}

	}
	else
		ft_putstr ("please entre 5 arguments \n");
}
