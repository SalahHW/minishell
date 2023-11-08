/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:56:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 09:49:29 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	only_char_after(char *str, char c)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (c == str[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	start_after_n(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (ft_strncmp(arg[i], "-n", 3) == 0)
			i++;
		else if (ft_strlen(arg[i]) != ft_strlen("-n")
			&& (only_char_after(arg[i], 'n')) == 0)
			i++;
		else
			return (i);
	}
	return (i);
}

int	ft_echo(t_shell *exec)
{
	int	n;
	int	i;

	i = start_after_n(exec->execlist->arg);
	if (exec->execlist->arg[1] && ft_strncmp(exec->execlist->arg[1], "-n",
			3) == 0)
		n = 1;
	else
		n = 0;
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
