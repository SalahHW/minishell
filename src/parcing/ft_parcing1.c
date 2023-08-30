/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:28:54 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/24 11:21:46 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_valid_sort(char **tab)
{
	int	i;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) == -1)
			return (0);
		i++;
	}
	printf("i = %d tab= %d\n", i, ft_tab_size(tab));
	if (i == ft_tab_size(tab) - 1)
		return (1);
	else
		return (0);
}

void	ft_export(t_mini *mini)
{
	int	i;

	i = 1;
	mini->expt = malloc(sizeof(char *) * (ft_tab_size(mini->env)));
	while (mini->env[i])
	{
		mini->expt[i - 1] = ft_strdup(mini->env[i]);
		i++;
	}
	i = 1;
	while (ft_valid_sort(mini->expt) == 0)
	{
		if (ft_strcmp(mini->expt[i - 1], mini->expt[i]) == -1)
		{
			ft_swap_string(mini->expt[i - 1], mini->expt[i]);
			i = 1;
		}
		else
			i++;
	}
	ft_print_tab(mini->expt);
}

void	ft_env(char **env, t_mini *mini)
{
	int		i;
	char	*temp;

	i = 0;
	mini->env = malloc(sizeof(char *) * (ft_tab_size(env) + 1));
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == -1)
		{
			mini->path = ft_split(env[i] + 5, ':');
		}
		mini->env[i] = ft_strdup(env[i]);
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
void	ft_arg_to_mini(char **env, t_mini *mini)
{
	ft_env(env, mini);
	ft_export(mini);
}