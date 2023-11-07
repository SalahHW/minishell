/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/07 07:24:12 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_valid_env_varname(char *varname)
{
	int	i;

	i = 0;
	if (!ft_isalpha(varname[i]) && varname[i] != '_')
		return (0);
	i++;
	while (varname[i])
	{
		if (!ft_isalnum(varname[i]) && varname[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static char	*get_varname(char *str)
{
	char	*varname;
	char	*equal_ptr;

	equal_ptr = ft_strchr(str, '=');
	if (equal_ptr)
	{
		if (equal_ptr != str)
			*equal_ptr = '\0';
	}
	varname = ft_strdup(str);
	if (equal_ptr)
		*equal_ptr = '=';
	return (varname);
}

static char	*get_varvalue(char *str)
{
	char	*equal_ptr;
	char	*varvalue;

	equal_ptr = ft_strchr(str, '=');
	if (!equal_ptr)
		return (NULL);
	varvalue = equal_ptr + 1;
	varvalue = ft_strdup(varvalue);
	*equal_ptr = '\0';
	return (varvalue);
}

static int	export_error(char *varname, char *varvalue)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(varname, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	free(varname);
	if (varvalue)
		free(varvalue);
	return (1);
}

int	ft_export(t_shell *exec)
{
	char	*varname;
	char	*varvalue;
	int		exit_code;
	int		i;

	i = 1;
	exit_code = 0;
	if (!exec->execlist->arg[i])
		return (print_exported_vars(exec->environement_list));
	while (exec->execlist->arg[i])
	{
		varname = get_varname(exec->execlist->arg[i]);
		varvalue = get_varvalue(exec->execlist->arg[i]);
		if (is_valid_env_varname(varname))
			export_variable(exec->environement_list, varname, varvalue);
		else
			exit_code = export_error(varname, varvalue);
		i++;
	}
	return (exit_code);
}
