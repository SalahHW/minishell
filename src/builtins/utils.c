/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 05:23:38 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/04 06:44:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	export_variable(t_envlist *env_list, char *varname, char *varvalue)
{
	t_env	*var_node;

	var_node = get_var_node(env_list, varname);
	if (!var_node)
		add_new_var(env_list, varname, varvalue);
	else
	{
		if (varvalue)
		{
			if (var_node->var_value)
				free(var_node->var_value);
			var_node->var_value = varvalue;
		}
		free(varname);
	}
	return (0);
}

int	print_exported_vars(t_envlist *env_list)
{
	t_env	**env_node_array;
	int		i;

	i = 0;
	env_node_array = get_node_array(env_list);
	env_node_array = sort_env_array(env_node_array,
			environement_list_size(env_list));
	while (env_node_array[i])
	{
		printf("declare -x %s", env_node_array[i]->var_name);
		if (env_node_array[i]->var_value)
			printf("=\"%s\"", env_node_array[i]->var_value);
		printf("\n");
		i++;
	}
	free(env_node_array);
	return (0);
}
