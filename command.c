/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:24:07 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/16 15:02:44 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_error(char *args, int status, char *msg)
{
	perror(msg);
	free(args);
	exit(status);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		free_split(args);
		exit_error(NULL, CMD_NOT_FOUND, "No command provided");
	}
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		free_split(args);
		exit_error(NULL, CMD_NOT_FOUND, "Command not found");
	}
	if (access(path, X_OK) != 0)
	{
		free_split(args);
		exit_error(path, CMD_NO_PERMISSION, "Path");
	}
	execve(path, args, envp);
	free_split(args);
	exit_error(path, EXIT_FAILURE, "Execve failed");
}
