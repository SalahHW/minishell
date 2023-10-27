/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:11:23 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/26 17:53:52 by sbouheni         ###   ########.fr       */
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

static char	*get_cmd_path(char *path, char *cmd)
{
	char	*cmd_path;
	char	*tmp;

	cmd_path = ft_strjoin(path, "/");
	tmp = cmd_path;
	cmd_path = ft_strjoin(cmd_path, cmd);
	free(tmp);
	return (cmd_path);
}

static int	is_executable_cmd(char *cmd_path)
{
	if (access(cmd_path, X_OK) == 0)
	{
		free(cmd_path);
		return (1);
	}
	return (0);
}

static int	is_path_cmd(t_envlist *envlist, char *cmd)
{
	char	*path;
	char	**paths;
	char	*cmd_path;
	int		i;

	path = get_var_value(envlist, "PATH");
	if (!path)
		return (0);
	paths = ft_split(path, ':');
	if (!paths)
		return (0);
	i = 0;
	while (paths[i])
	{
		cmd_path = get_cmd_path(paths[i], cmd);
		if (is_executable_cmd(cmd_path))
		{
			p_free_splited_str(paths);
			return (1);
		}
		free(cmd_path);
		i++;
	}
	p_free_splited_str(paths);
	return (0);
}

int	is_valid_command(t_shell *shell, char *cmd)
{
	if (is_bultin_cmd(cmd))
		return (1);
	if (is_path_cmd(shell->environement_list, cmd))
		return (1);
	printf("%s: command not found\n", cmd);
	return (0);
}
