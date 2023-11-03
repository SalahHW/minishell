/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:24:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/03 10:18:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*get_var_node(t_envlist *envlist, char *varname)
{
	t_env	*env_ptr;

	env_ptr = envlist->head;
	while (env_ptr)
	{
		if (!ft_strncmp(env_ptr->var_name, varname, ft_strlen(varname) + 1))
			return (env_ptr);
		env_ptr = env_ptr->next;
	}
	return (NULL);
}

t_env	**get_node_array(t_envlist *envlist)
{
	t_env	*env_ptr;
	t_env	**env_node_array;
	int		i;
	int		len;

	i = 0;
	len = environement_list_size(envlist);
	env_node_array = malloc(sizeof(t_env *) * len + 1);
	env_ptr = envlist->head;
	while (env_ptr)
	{
		env_node_array[i] = env_ptr;
		env_ptr = env_ptr->next;
		i++;
	}
	env_node_array[i] = NULL;
	return (env_node_array);
}
