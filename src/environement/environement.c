/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:44:18 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 04:58:59 by sbouheni         ###   ########.fr       */
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
		if (!ft_strncmp(env_ptr->var_name, varname, varname_len + 1))
			return (env_ptr->var_value);
		env_ptr = env_ptr->next;
	}
	return (NULL);
}

char	**environement_list_to_array(t_envlist *envlist)
{
	t_env	*env_ptr;
	char	**env_array;
	char	*variable;
	char	*tmp;
	int		i;

	i = 0;
	env_ptr = envlist->head;
	env_array = malloc(sizeof(char **) * (environement_list_size(envlist) + 1));
	while (env_ptr)
	{
		tmp = ft_strjoin(env_ptr->var_name, "=");
		variable = ft_strjoin(tmp, env_ptr->var_value);
		free(tmp);
		env_array[i] = variable;
		i++;
		env_ptr = env_ptr->next;
	}
	env_array[i] = NULL;
	return (env_array);
}
