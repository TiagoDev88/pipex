/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:52:47 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/15 15:22:54 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_pipe(int fd_pipe[2])
{
	if (pipe(fd_pipe) == -1)
	{
		perror("Error creating pipe");
		return (-1);
	}
	return (0);
}

int	open_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror(infile);
	return (fd);
}

int	open_outfile(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror(outfile);
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_pipe[2];
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (error_msg("Invalid number of arguments"));
	fd_in = open_infile(argv[1]);
	fd_out = open_outfile(argv[4]);
	if (fd_out == -1)
		return (1);
	if (create_pipe(fd_pipe) == -1)
		return (error_msg("Pipe error"));
	pid1 = child1(argv[2], envp, fd_in, fd_pipe);
	pid2 = child2(argv[3], envp, fd_out, fd_pipe);
	close_fds(fd_pipe, fd_in, fd_out);
	waitpid(pid1, NULL, 0);
	fd_out = 0;
	waitpid(pid2, &fd_out, 0);
	if (WIFEXITED(fd_out))
		return (WEXITSTATUS(fd_out));
	return (0);
}
