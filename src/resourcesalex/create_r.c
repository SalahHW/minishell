/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:27:44 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/27 16:37:25 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_path_home(t_mini *mini, char **env)
{
	int		i;
	char	*temp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			mini->path = ft_split(env[i] + 5, ':');
		}
		if (ft_strncmp(env[i], "HOME", 4) == 0)
		{
			mini->home = ft_strdup(env[i] + 5);
		}
		i++;
	}
	i = 0;
	while (mini->path[i])
	{
		temp = mini->path[i];
		mini->path[i] = ft_strjoin(mini->path[i], "/");
		free(temp);
		i++;
	}
}
void	ft_env(t_mini *mini, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	mini->env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		mini->env[i] = ft_strdup(env[i]);
		i++;
	}
	mini->env[i] = NULL;
	mini->expt = ft_ascii_sort(ft_tab_copy(mini->env));
	ft_print_tab_for_test(mini->expt);
	printf("\n\n\n\n\n");
}
void	ft_create_env_and_path(t_mini *mini, char **env)
{
	ft_init_mini(mini);
	ft_path_home(mini, env);
	ft_env(mini, env);
}