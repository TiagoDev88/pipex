/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:07:23 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/11 19:48:08 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

int	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}

#include <unistd.h>

void	close_fds(int *pipefd, int fd1, int fd2)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd1);
	close(fd2);
}

pid_t	fork_process(char *cmd, char **envp, int fd_in, int fd_out, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);

		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execute_command(cmd, envp);
	}
	return (pid);
}
