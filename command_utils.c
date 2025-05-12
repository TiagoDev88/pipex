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
	
	//ft_putstr_fd(cmd, 2);

	//if (ft_strchr(cmd, 34))
	//	cmd = ft_strtrim(cmd, "\"");
	/*ft_putendl_fd(cmd, 2);
	if (ft_strchr(cmd, 34))
	{
		ft_putendl_fd("Divide em aspas",2);
		args = ft_split(cmd, 34);	
	}
	else
	{
		ft_putendl_fd("Divide em espacos",2);
		*/
	args = ft_split(cmd, ' ');
/*	}
	int i = 0;
	while (args[i] != NULL)
	{
		ft_putendl_fd(args[i], 2);
		i++;
	}*/
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
	//path = ft_strjoin(path, args[1]);
	execve(path, args, envp);
	perror("Execve failed");
	exit(1);
}
