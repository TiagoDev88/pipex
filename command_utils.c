/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:14:42 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/11 19:14:45 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		perror("Invalid command");
		exit(1);
	}
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		perror("Command not found");
		exit(127);
	}
	execve(path, args, envp);
	perror("Execve failed");
	exit(1);
}
