/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/03 09:27:41 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	unset(t_shell *exec)
{
	(void)exec;
	// char	*tmp;
	// char	*tmp2;
	// int		i;

	// i = 0;
	// while (exec->execlist->arg[i])
	// {
	// 	tmp = get_var_value(exec->export_list,
	// 			extract_varname(exec->execlist->arg[i]));
	// 	if (tmp != NULL)
	// 		remove_var(exec->export_list, tmp);
	// 	tmp2 = get_var_value(exec->environement_list,
	// 			extract_varname(exec->execlist->arg[i]));
	// 	if (tmp2 != NULL)
	// 		remove_var(exec->environement_list, tmp2);
	// 	i++;
	// }
	return (0);
}
