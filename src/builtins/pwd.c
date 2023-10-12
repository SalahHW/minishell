/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:45:53 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/09 09:26:34 by aherrman         ###   ########.fr       */
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

int	pwd_change(t_exec *exec)
{
	if (ft_search_in_tab(exec->general->env, "PWD") != NULL)
	{
		if (ft_search_in_tab(exec->general->env, "OLDPWD") != NULL)
			exec->general->env = ft_change_value_in_var_in_tab(exec->general->env, "OLDPWD",
					ft_search_var_in_env(exec->general->env, "PWD", 2));
		exec->general->env = ft_change_value_in_var_in_tab(exec->general->env, "PWD", getcwd(NULL,
					0));
	}
	else if (ft_search_in_tab(exec->general->env, "OLDPWD") != NULL)
		exec->general->env = ft_delete_elem_in_tab("OLDPWD",exec->general->env);
	return (0);
}