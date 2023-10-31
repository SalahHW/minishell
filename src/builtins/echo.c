/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:56:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/31 14:12:58 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(t_shell *exec)
{
	int	n;

	if (exec->execlist->arg[1] && ft_strncmp(exec->execlist->arg[1], "-n",
			3) == 0)
		n = 1;
	else
		n = 0;
	if (n == 1)
		printf("%s ", ft_tab_on_one_line(exec->execlist->arg + 2));
	else
		printf("%s \n", ft_tab_on_one_line(exec->execlist->arg + 1));
	return (0);
}
// PERROR a lire
