/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:44:18 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/25 16:30:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_envlist	*get_parent_environement(char **env)
{
	char		*varname;
	char		*varvalue;
	t_envlist	*envlist;

	envlist = init_environement_list();
	while (*env)
	{
		varname = extract_varname(*env);
		varvalue = extract_varvalue(*env);
		add_new_var(envlist, varname, varvalue);
		env++;
	}
	return (envlist);
}

char	*get_var_value(t_envlist *envlist, char *varname)
{
	t_env	*env_ptr;
	int		varname_len;

	varname_len = ft_strlen(varname);
	env_ptr = envlist->head;
	while (env_ptr)
	{
		if (ft_strncmp(env_ptr->var_name, varname, varname_len + 1) == 0)
			return (env_ptr->var_value);
		env_ptr = env_ptr->next;
	}
	return (NULL);
}