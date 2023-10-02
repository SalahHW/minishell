/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:45:53 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/02 16:48:04 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd(void)
{
	char	*pwd;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (1);
	printf("%s\n", pwd);
	free(pwd);
	// return (mini_error("pwd",NULL,0));
	return (0);
}

int	pwd_change(t_mini *mini)
{
	if (ft_search_in_tab(mini->env, "PWD") != NULL)
	{
		if (ft_search_in_tab(mini->env, "OLDPWD") != NULL)
			mini->env = ft_change_value_in_var_in_tab(mini->env, "OLDPWD",
					ft_search_var_in_env(mini->env, "PWD", 2));
		mini->env = ft_change_value_in_var_in_tab(mini->env, "PWD", getcwd(NULL,
					0));
	}
	else if (ft_search_in_tab(mini->env, "OLDPWD") != NULL)
		mini->env = ft_delete_elem_in_tab("OLDPWD", mini->env);
	return (0);
}
