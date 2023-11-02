/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:36:30 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/02 03:00:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**get_paths_array(t_envlist *env_list)
{
	char	*path;
	char	**path_array;
	char	*temp;
	int		i;

	i = 0;
	path = get_var_value(env_list, "PATH");
	path_array = ft_split(path, ':');
	while (path_array[i])
	{
		temp = path_array[i];
		path_array[i] = ft_strjoin(path_array[i], "/");
		free(temp);
		i++;
	}
	return (path_array);
}

void get_cmd_path(t_shell *shell)
{
	char *cmd_full_path;
	char **path_array;
	int i;

	i = 0;
	path_array = get_paths_array(shell->environement_list);
	while (path_array[i])
	{
		cmd_full_path = ft_strjoin(path_array[i], shell->execlist->cmd_path);
		// printf("cmd_full_path: %s\n", cmd_full_path);
		if (access(cmd_full_path, F_OK) == 0)
		{
			free(shell->execlist->cmd_path);
			shell->execlist->cmd_path = ft_strdup(cmd_full_path);
			break;
		}
		free(cmd_full_path);
		i++;
	}
	free_tab(path_array);
}