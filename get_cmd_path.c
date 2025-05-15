/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:22:48 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/15 14:25:18 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*concatenate_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full)
		return (NULL);
	return (full);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*find_cmd_in_paths(char **paths, char *cmd)
{
	char	*full_path;
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	while (paths[i] && result == NULL)
	{
		full_path = concatenate_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
			result = full_path;
		else
			free(full_path);
		i++;
	}
	free_split(paths);
	return (result);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*result;
	int		i;

	result = NULL;
	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == 0)
		result = ft_strdup(cmd);
	else
	{
		i = 0;
		while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
			i++;
		if (envp[i])
		{
			paths = ft_split(envp[i] + 5, ':');
			if (paths)
				result = find_cmd_in_paths(paths, cmd);
		}
	}
	return (result);
}
