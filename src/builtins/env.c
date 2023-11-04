/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:09:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/04 06:30:26 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env(t_shell *shell)
{
	t_env	*env_ptr;

	env_ptr = shell->environement_list->head;
	while (env_ptr)
	{
		if (env_ptr->var_value)
			printf("%s=%s\n", env_ptr->var_name, env_ptr->var_value);
		env_ptr = env_ptr->next;
	}
	return (0);
}
