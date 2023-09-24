/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:11:23 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/24 18:57:34 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_bultin_cmd(char *cmd)
{
	char	*builtins_cmd[8];
	int		i;

	builtins_cmd[0] = "echo";
	builtins_cmd[1] = "cd";
	builtins_cmd[2] = "pwd";
	builtins_cmd[3] = "export";
	builtins_cmd[4] = "unset";
	builtins_cmd[5] = "env";
	builtins_cmd[6] = "exit";
	builtins_cmd[7] = 0;
	i = 0;
	while (builtins_cmd[i])
	{
		if (ft_strncmp(cmd, builtins_cmd[i], ft_strlen(builtins_cmd[i])) == 0
			&& ft_strlen(cmd) == ft_strlen(builtins_cmd[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_command(char *cmd)
{
	if (is_bultin_cmd(cmd))
		return (1);
	//	if (is_path_cmd(cmd))
	//		return (1);
	return (0);
}
