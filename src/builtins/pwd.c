/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:45:53 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 15:40:28 by aherrman         ###   ########.fr       */
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

int	pwd_change(t_shell *shell)
{
	if (ft_search_in_tab(shell->env, "PWD") != NULL)
	{
		if (ft_search_in_tab(shell->env, "OLDPWD") != NULL)
			shell->env = ft_change_value_in_var_in_tab(shell->env, "OLDPWD",
					ft_search_var_in_env(shell->env, "PWD", 2));
		shell->env = ft_change_value_in_var_in_tab(shell->env, "PWD", getcwd(NULL,
					0));
	}
	else if (ft_search_in_tab(shell->env, "OLDPWD") != NULL)
		shell->env = ft_delete_elem_in_tab("OLDPWD", shell->env);
	return (0);
}
