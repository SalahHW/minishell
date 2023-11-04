/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/04 06:26:13 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	export_variable(t_envlist *env_list, char *varname, char *varvalue)
{
	t_env	*var_node;

	var_node = get_var_node(env_list, varname);
	if (!var_node)
		add_new_var(env_list, varname, varvalue);
	else
	{
		if (varvalue)
		{
			if (var_node->var_value)
				free(var_node->var_value);
			var_node->var_value = varvalue;
		}
		free(varname);
	}
	return (0);
}

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

int	ft_export(t_shell *exec)
{
	char	*varname;
	char	*varvalue;
	int		i;

	i = 1;
	if (!exec->execlist->arg[i])
		return (print_exported_vars(exec->environement_list));
	while (exec->execlist->arg[i])
	{
		varname = get_varname(exec->execlist->arg[i]);
		varvalue = get_varvalue(exec->execlist->arg[i]);
		if (is_valid_env_varname(varname))
			export_variable(exec->environement_list, varname, varvalue);
		else
		{
			printf("%s: export: `%s': not a valid identifier\n", exec->prompt,
				varname);
			if (varname)
				free(varname);
			if (varvalue)
				free(varvalue);
		}
		i++;
	}
	return (0);
}
