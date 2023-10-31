/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/30 16:03:01 by aherrman         ###   ########.fr       */
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
int	check_if_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
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
void	ft_del_if_need(t_shell *shell, char *str)
{
	char	*tmp;

	printf("%s\n", str);
	printf("i = %d j = %d\n", ft_tab_size(shell->general->env),
		ft_tab_size(shell->general->expt));
	tmp = ft_search_var_in_env(shell->general->env, str, 0);
	if (tmp == NULL)
		return ;
	else
	{
		printf("tmp = %s\n", tmp);
		shell->general->env = ft_delete_elem_in_tab(tmp, shell->general->env);
	}
	tmp = ft_search_var_in_env(shell->general->expt, str, 0);
	if (tmp == NULL)
		return ;
	else
		shell->general->expt = ft_delete_elem_in_tab(tmp, shell->general->expt);
	printf("i = %d j = %d\n", ft_tab_size(shell->general->env),
		ft_tab_size(shell->general->expt));
}

int	ft_export(t_shell *exec)
{
	int	i;

	i = 1;
	if (exec->execlist->arg[i] == NULL)
	{
		ft_print_for_export(ft_ascii_sort(exec->general->expt));
		return (0);
	}
	while (exec->execlist->arg[i])
	{
		ft_del_if_need(exec, exec->execlist->arg[i]);
		if (ft_check_char_in_str(exec->execlist->arg[i], '='))
		{
			exec->general->expt = add_char_at_back_tab(exec->general->expt,
					exec->execlist->arg[i]);
			exec->general->env = add_char_at_back_tab(exec->general->env,
					exec->execlist->arg[i]);
		}
		else
			exec->general->expt = add_char_at_back_tab(exec->general->expt,
					exec->execlist->arg[i]);
		i++;
	}
	return (0);
}
