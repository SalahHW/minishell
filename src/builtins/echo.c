/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:56:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/01 09:55:46 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(t_shell *exec)
{
	int	n;
	int	i;

	if (exec->execlist->arg[1] && ft_strncmp(exec->execlist->arg[1], "-n",
			3) == 0)
	{
		n = 1;
		i = 2;
	}
	else
	{
		i = 1;
		n = 0;
	}
	while (exec->execlist->arg[i])
	{
		ft_putstr_fd(exec->execlist->arg[i], 1);
		if (ft_tab_size(exec->execlist->arg) > i + 1)
			write(1, " ", 1);
		i++;
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}
