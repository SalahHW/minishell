/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:10:35 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 11:59:00 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(char *arg, char **envp, char *home)
{
	int	err;

	err = 0;
	(void) envp;
	if (arg && ft_only_spaces(arg) == 0)
	{
		err = chdir(home);
		return (1);
	}
	else if (arg && arg[0])
		if (arg[0] == '~')
			;
		else
			err = chdir(arg);
	else if (arg && ft_only_spaces(arg) == 0)
		err = chdir(home);
	if (err != 0)
		return (1);
	else
		return (0);
}
