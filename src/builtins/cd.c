/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:10:35 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/02 16:39:44 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(char *arg, char **envp, char *home)
{
	int	err;

	err = 0;
	if (arg == NULL && ft_search_in_tab(envp,"HOME") != NULL)
		return (1);
	else if (arg == NULL)
		err = chdir(home);
	else
		err = chdir(arg);
	if (err != 0)
		return (1);
	return (0);
}
