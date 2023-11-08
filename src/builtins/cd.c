/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:10:35 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 15:35:34 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_old_pwd(t_envlist *env_list, t_env *pwd, t_env *oldpwd)
{
	if (oldpwd)
	{
		if (oldpwd->var_value)
			free(oldpwd->var_value);
		if (pwd)
			oldpwd->var_value = ft_strdup(pwd->var_value);
	}
	else
	{
		if (pwd)
			add_new_var(env_list, ft_strdup("OLDPWD"),
				ft_strdup(pwd->var_value));
	}
}

static void	handle_pwd(t_envlist *env_list, t_env *pwd)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return ;
	if (pwd)
	{
		if (pwd->var_value)
			free(pwd->var_value);
		pwd->var_value = ft_strdup(current_dir);
	}
	else
		add_new_var(env_list, ft_strdup("PWD"), ft_strdup(current_dir));
	free(current_dir);
}

static void	update_pwd(t_envlist *environement_list)
{
	t_env	*pwd;
	t_env	*oldpwd;

	pwd = get_var_node(environement_list, "PWD");
	oldpwd = get_var_node(environement_list, "OLDPWD");
	handle_old_pwd(environement_list, pwd, oldpwd);
	handle_pwd(environement_list, pwd);
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
