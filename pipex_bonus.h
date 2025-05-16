/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:09:55 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/16 15:11:30 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h> 
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"
# include "pipex.h"


/* ******************************* MAIN ************************************* */
int		create_pipe(int fd_pipe[2]);
int		open_infile(char *infile);
int		open_outfile(char *outfile);
int		exec_every(char **argv, char **envp);

/* ******************************* UTILS ************************************ */


#endif