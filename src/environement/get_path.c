/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:36:30 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/06 09:47:35 by aherrman         ###   ########.fr       */
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
	if (path == NULL)
		return (NULL);
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

void	get_cmd_path(t_shell *shell)
{
	char	*cmd_full_path;
	char	**path_array;
	int		i;

	i = 0;
	path_array = get_paths_array(shell->environement_list);
	if (path_array == NULL)
		return ;
	while (path_array[i])
	{
		cmd_full_path = ft_strjoin(path_array[i], shell->execlist->cmd_path);
		if (access(cmd_full_path, F_OK) == 0)
		{
			free(shell->execlist->cmd_path);
			shell->execlist->cmd_path = ft_strdup(cmd_full_path);
			free(cmd_full_path);
			break ;
		}
		free(cmd_full_path);
		i++;
	}
	free_tab(path_array);
}
