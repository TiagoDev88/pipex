/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:52:47 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/11 19:49:30 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

int create_pipe(int fd_pipe[2])
{
    if (pipe(fd_pipe) == -1)
    {
        perror("Error creating pipe");
        return (-1);
    }
    return (0);
}

int	open_files(char *infile, char *outfile, int *fd_in, int *fd_out)
{
    *fd_in = open(infile, O_RDONLY);
    if (*fd_in == -1)
    {
        perror("Error opening input file");
        return (-1);
    }
    *fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*fd_out == -1)
    {
        perror("Error opening output file");
        close(*fd_in);
        return (-1);
    }
    return (0);
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
	if (open_files(argv[1], argv[4], &fd_in, &fd_out) == -1)
		return (1);
	if (pipe(fd_pipe) == -1)
		return (error_msg("Pipe error"));
	//ft_printf("%s\n", argv[2]);
	//argv[2] = ft_strtrim(argv[2], "\"");
	//ft_printf("%s\n", argv[2]);
	//ft_printf("%s\n", argv[3]);
	pid1 = child1(argv[2], envp, fd_in, fd_pipe[1], fd_pipe);
	pid2 = child2(argv[3], envp, fd_pipe[0], fd_out, fd_pipe);
	close_fds(fd_pipe, fd_in, fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
