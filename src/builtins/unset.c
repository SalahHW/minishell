/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/06 11:44:09 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	remove_var_from_env(t_envlist *env_list, char *varname)
{
	t_env	*env_ptr;

	env_ptr = env_list->head;
	while (env_ptr)
	{
		if (!ft_strncmp(env_ptr->var_name, varname, ft_strlen(varname) + 1))
		{
			delete_var(env_list, env_ptr);
			break ;
		}
		env_ptr = env_ptr->next;
	}
}

int	unset(t_shell *exec)
{
	char	*varname;
	int		i;

	i = 0;
	while (exec->execlist->arg[i])
	{
		varname = extract_varname(exec->execlist->arg[i]);
		remove_var_from_env(exec->environement_list, varname);
		free(varname);
		i++;
	}
	return (0);
}
