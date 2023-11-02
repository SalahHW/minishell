/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:45:53 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/02 11:01:00 by aherrman         ###   ########.fr       */
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
	return (0);
}

int	pwd_change(t_shell *exec)
{
	char	*tmp;

	if (ft_search_in_tab(exec->general->env, "PWD") != NULL)
	{
		if (ft_search_in_tab(exec->general->env, "OLDPWD") != NULL)
			exec->general->env = ft_change_value_in_var_in_tab(exec->general->env,
					"OLDPWD", ft_search_var_in_env(exec->general->env, "PWD",
						2));
		tmp = getcwd(NULL, 0);
		exec->general->env = ft_change_value_in_var_in_tab(exec->general->env,
				"PWD", tmp);
		free(tmp);
	}
	else if (ft_search_in_tab(exec->general->env, "OLDPWD") != NULL)
		exec->general->env = ft_delete_elem_in_tab("OLDPWD",
				exec->general->env);
	return (0);
}
int	pwd_change(t_shell *shell)
{
	char	*tmp;

	if (ft_search_in_list(shell->environement_list->head, "PWD") == 1)
	{
		if (ft_search_in_list(shell->environement_list->head, "OLDPWD") == 1)
		{
			remove_var(shell->environement_list, "OLDPWD");
			tmp = get_var_value(shell->environement_list, "PWD");
			add_new_var(shell->environement_list, "OLDPWD", tmp);
			free(tmp);
			remove_var(shell->environement_list, "PWD");
			tmp = getcwd(NULL, 0);
			add_new_var(shell->environement_list, "PWD", tmp);
			free(tmp);
		}
	}
	else if (ft_search_in_list(shell->environement_list->head, "OLDPWD") == 0)
		remove_var(shell->environement_list, "OLDPWD");
}
