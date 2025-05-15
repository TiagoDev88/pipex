/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:07:23 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/15 15:13:39 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (1);
}

void	close_fds(int *pipefd, int fd1, int fd2)
{
	close(pipefd[0]);
	close(pipefd[1]);
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
}

pid_t	child1(char *cmd, char **envp, int fd_file, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork Child1");
		exit(1);
	}
	if (pid == 0)
	{
		if (fd_file == -1)
			exit(1);
		dup2(fd_file, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(fd_file);
		close(pipefd[0]);
		execute_command(cmd, envp);
	}
	return (pid);
}

pid_t	child2(char *cmd, char **envp, int fd_file, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork Child2");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd_file, STDOUT_FILENO);
		close(pipefd[1]);
		close(fd_file);
		execute_command(cmd, envp);
	}
	return (pid);
}
