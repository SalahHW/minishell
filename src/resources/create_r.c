/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:27:44 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/01 10:13:47 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_path_home(t_shell *shell, char **env)
{
	int		i;
	char	*temp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			shell->general->path = ft_split(env[i] + 5, ':');
		}
		if (ft_strncmp(env[i], "HOME", 4) == 0)
		{
			shell->general->home = ft_strdup(env[i] + 5);
		}
		i++;
	}
	i = 0;
	while (i < ft_tab_size(shell->general->path))
	{
		temp = shell->general->path[i];
		shell->general->path[i] = ft_strjoin(shell->general->path[i], "/");
		free(temp);
		i++;
	}
}
void	ft_env(t_shell *shell, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	shell->general->env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		shell->general->env[i] = ft_strdup(env[i]);
		i++;
	}
	shell->general->env[i] = NULL;
	shell->general->expt = ft_tab_copy(shell->general->env);
}
void	ft_save_fd(t_shell *shell)
{
	shell->general->fd_in = dup(STDIN_FILENO);
	shell->general->fd_out = dup(STDOUT_FILENO);
}
void	ft_create_env_and_path(t_shell *shell)
{
	char **env;
	
	env = environement_list_to_array(shell->environement_list);
	ft_path_home(shell, env);
	ft_env(shell, env);
	ft_save_fd(shell);
	free(env);
}