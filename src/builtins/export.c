/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/02 10:32:01 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_print1(char *str)
{
	int	i;

	i = 0;
	write(1, "declare -x ", 11);
	while (str[i])
	{
		if (str[i] == '=')
		{
			write(1, "=\"", 2);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	write(1, "\"\n", 2);
}
void	export_print2(char *str)
{
	int	i;

	i = 0;
	write(1, "declare -x ", 11);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_for_export(char **tmp)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (tmp[j])
	{
		if (check_if_egal(tmp[j]) == 1)
			export_print1(tmp[j]);
		else
		{
			write(1, "declare -x ", 11);
			while (tmp[j][i])
			{
				write(1, &tmp[j][i], 1);
				i++;
			}
			write(1, "\n", 1);
		}
		j++;
	}
}
int	ft_del_if_need(t_shell *shell, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strncmp(str, "=", 2) == 0)
	{
		error(shell->execlist->arg[0], NULL, 2);
		return (1);
	}
	tmp = get_var_value(shell->export_list, extract_varname(str));
	if (tmp != NULL)
		remove_var(shell->export_list, tmp);
	tmp2 = get_var_value(shell->environement_list, extract_varname(str));
	if (tmp2 != NULL )
		remove_var(shell->environement_list, tmp2);
	free(tmp);
	free(tmp2);
	return (0);
}

int	ft_export(t_shell *exec)
{
	int		i;
	char	**tmp;

	i = 1;
	if (exec->execlist->arg[i] == NULL)
	{
		tmp = environement_list_to_array(exec->export_list);
		ft_print_for_export(ft_ascii_sort(tmp));
		free(tmp);
		return (0);
	}
	while (exec->execlist->arg[i])
	{
		if (ft_del_if_need(exec, exec->execlist->arg[i]) == 1)
			return (0);
		if (check_if_egal(exec->execlist->arg[i]) == 0)
			ft_add_list(exec->export_list, exec->execlist->arg[i]);
		else
		{
			ft_add_list(exec->export_list, exec->execlist->arg[i]);
			ft_add_list(exec->environement_list, exec->execlist->arg[i]);
		}
		i++;
	}
	return (0);
}
