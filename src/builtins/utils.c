/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 05:23:38 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/04 05:25:05 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
