/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:52:50 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/12 13:15:24 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h> 
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

void	close_fds(int *pipefd, int fd1, int fd2);
int 	error_msg(char *msg);
void 	execute_command(char *cmd, char **envp);
pid_t 	child1(char *cmd, char **envp, int fd_in, int fd_out, int *pipefd);
pid_t 	child2(char *cmd, char **envp, int fd_in, int fd_out, int *pipefd);
char 	*get_cmd_path(char *cmd, char **envp);
int		create_pipe(int fd_pipe[2]);
int		open_files(char *infile, char *outfile, int *fd_in, int *fd_out);
void 	free_split(char **arr);

#endif
