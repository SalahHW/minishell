/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/03 13:24:56 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	export_print1(char *str)
// {
// 	int	i;
//
// 	i = 0;
// 	write(1, "declare -x ", 11);
// 	while (str[i])
// 	{
// 		if (str[i] == '=')
// 		{
// 			write(1, "=\"", 2);
// 		}
// 		else
// 		{
// 			write(1, &str[i], 1);
// 		}
// 		i++;
// 	}
// 	write(1, "\"\n", 2);
// }
// void	export_print2(char *str)
// {
// 	int	i;
//
// 	i = 0;
// 	write(1, "declare -x ", 11);
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }
//
// void	ft_print_for_export(char **tmp)
// {
// 	int	j;
// 	int	i;
//
// 	i = 0;
// 	j = 0;
// 	while (tmp[j])
// 	{
// 		if (check_if_egal(tmp[j]) == 1)
// 			export_print1(tmp[j]);
// 		else
// 		{
// 			write(1, "declare -x ", 11);
// 			while (tmp[j][i])
// 			{
// 				write(1, &tmp[j][i], 1);
// 				i++;
// 			}
// 			write(1, "\n", 1);
// 		}
// 		j++;
// 	}
// }
// // int	ft_del_if_need(t_shell *shell, char *str)
// // {
// // 	char	*tmp;
// // 	char	*tmp2;
// //
// // 	if (ft_strncmp(str, "=", 2) == 0)
// // 	{
// // 		error(shell->execlist->arg[0], NULL, 2);
// // 		return (1);
// // 	}
// // 	tmp = get_var_value(shell->export_list, extract_varname(str));
// // 	if (tmp != NULL)
// // 		remove_var(shell->export_list, tmp);
// // 	tmp2 = get_var_value(shell->environement_list, extract_varname(str));
// // 	if (tmp2 != NULL)
// // 		remove_var(shell->environement_list, tmp2);
// // 	return (0);
// // }
//
// // static void	print_export_list(t_envlist *export_list)
// // {
// // 	char	**export_array;
// //
// // 	export_array = environement_list_to_array(export_list);
// // 	ft_print_for_export(ft_ascii_sort());
// // 	free(export_array);
// // }
// //
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

// char	**ft_ascii_sort(char **arg)
// {
// 	int		i;
// 	int		j;
// 	int		l;
// 	char	*tmp;
//
// 	i = 0;
// 	j = 1;
// 	l = ft_tab_size(arg);
// 	while (j < l)
// 	{
// 		if (ft_strcmp(arg[i], arg[j]) > 0)
// 		{
// 			tmp = arg[i];
// 			arg[i] = arg[j];
// 			arg[j] = tmp;
// 			i = 0;
// 			j = 1;
// 		}
// 		else
// 		{
// 			i++;
// 			j++;
// 		}
// 	}
// 	return (arg);
// }
//
t_env	**sort_env_array(t_env **env, int size)
{
	int		i;
	int		j;
	t_env	*tmp;

	i = 0;
	j = 1;
	while (j < size)
	{
		if (ft_strcmp(env[i]->var_name, env[j]->var_name) > 0)
		{
			tmp = env[i];
			env[i] = env[j];
			env[j] = tmp;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (env);
}

static void	print_exported_vars(t_envlist *env_list)
{
	t_env	**env_node_array;
	int		i;

	i = 0;
	env_node_array = get_node_array(env_list);
	env_node_array = sort_env_array(env_node_array,
			environement_list_size(env_list));
	while (env_node_array[i])
	{
		printf("declare -x %s", env_node_array[i]->var_name);
		if (env_node_array[i]->var_value)
			printf("=\"%s\"", env_node_array[i]->var_value);
		printf("\n");
		i++;
	}
}
static int	export_variable(t_envlist *env_list, char *str)
{
	char	*varname;
	char	*varvalue;
	char	*equal_ptr;
	t_env	*var_node;

	equal_ptr = ft_strchr(str, '=');
	if (equal_ptr)
	{
		*equal_ptr = '\0';
		varname = str;
		varvalue = equal_ptr + 1;
	}
	else
	{
		varname = str;
		varvalue = NULL;
	}
	var_node = get_var_node(env_list, varname);
	if (var_node)
	{
		if (varvalue)
		{
			free(var_node->var_value);
			var_node->var_value = ft_strdup(varvalue);
		}
	}
	else
	{
		if (varvalue)
			add_new_var(env_list, ft_strdup(varname), ft_strdup(varvalue));
		else
			add_new_var(env_list, ft_strdup(varname), NULL);
	}
	return (0);
}

int	ft_export(t_shell *exec)
{
	int		i;

	i = 1;
	if (exec->execlist->arg[i] == NULL)
	{
		print_exported_vars(exec->environement_list);
		return (0);
	}
	while (exec->execlist->arg[i])
	{
		export_variable(exec->environement_list, exec->execlist->arg[i]);
		i++;
	}
	return (0);
}
