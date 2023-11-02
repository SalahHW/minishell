/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:09:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/02 09:51:07 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env(t_shell *shell)
{
	char **tmp;
	int i;

	i = 0;
	tmp = environement_list_to_array(shell->environement_list);
	while (tmp[i])
	{
		printf("%s\n", tmp[i]);
		i++;
	}
	free_tab(tmp);
	return (0);
}