/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:10:35 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 12:47:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	update_pwd(t_envlist *environement_list)
{
	char	*current_dir;
	t_env	*pwd;
	t_env	*oldpwd;

	current_dir = getcwd(NULL, 0);
	pwd = get_var_node(environement_list, "PWD");
	oldpwd = get_var_node(environement_list, "OLDPWD");
	if (!current_dir)
		return ;
	if (oldpwd)
	{
		free(oldpwd->var_value);
		if (pwd)
			oldpwd->var_value = ft_strdup(pwd->var_value);
	}
	else
	{
		if (pwd)
			add_new_var(environement_list, "OLDPWD", ft_strdup(pwd->var_value));
	}
	if (pwd)
	{
		free(pwd->var_value);
		pwd->var_value = ft_strdup(current_dir);
	}
	else
		add_new_var(environement_list, "PWD", ft_strdup(current_dir));
	free(current_dir);
}

static int	cd_argc_error(void)
{
	int	exit_code;

	exit_code = 1;
	ft_putstr_fd("cd: too many arguments\n", STDIN_FILENO);
	return (exit_code);
}

int	ft_cd(t_shell *exec)
{
	int		argc;
	int		exit_code;
	char	*home;

	exit_code = 0;
	home = get_var_value(exec->environement_list, "HOME");
	argc = ft_tab_size(exec->execlist->arg);
	if (argc > 2)
		return (cd_argc_error());
	if (!home && exec->execlist->arg[1] == NULL)
	{
		error("cd", NULL, 3);
		return (1);
	}
	else if (exec->execlist->arg[1] == NULL)
		exit_code = chdir(home);
	else
		exit_code = chdir(exec->execlist->arg[1]);
	if (exit_code == -1)
		error("cd", exec->execlist->arg[1], 10);
	if (exit_code != 0)
		return (1);
	update_pwd(exec->environement_list);
	return (0);
}
