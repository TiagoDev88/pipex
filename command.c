/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:24:07 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/15 14:24:07 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		perror("No command provided");
		free_split(args);
		exit(CMD_NOT_FOUND);
	}
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		perror("Command not found");
		free_split(args);
		exit(CMD_NOT_FOUND);
	}
	if (access(path, X_OK) != 0)
	{
		perror("Path");
		free(path);
		free_split(args);
		exit(CMD_NO_PERMISSION);
	}
	execve(path, args, envp);
	perror("Execve failed");
	free(path);
	free_split(args);
	exit(EXIT_FAILURE);
}
