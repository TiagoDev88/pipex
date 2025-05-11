/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:22:48 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/11 19:24:10 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

static char	*join_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

static char	**get_paths_from_env(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}

static char	*find_cmd_in_paths(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = get_paths_from_env(envp);
	if (!paths)
		return (NULL);
	return (find_cmd_in_paths(paths, cmd));
}

void	free_split(char **arr)
{
	int	i = 0;

	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

