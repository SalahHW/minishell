/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:45:53 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 08:50:48 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (1);
	// return (mini_error("pwd",NULL,0));
	printf("%s\n", pwd);
	return (0);
}

int	pwd_change(char **tab)
{
	if (ft_search_in_tab(tab, "PWD") != NULL)
	{
		if (ft_search_in_tab(tab, "OLDPWD") != NULL)
		{
			tab = ft_replace_in_tab(tab, "OLDPWD",
					ft_search_in_tab(tab, "PWD"));
			tab = ft_replace_in_tab(tab, "PWD", getcwd(NULL, 0));
		}
		else
			tab = ft_replace_in_tab(tab, "PWD", getcwd(NULL, 0));
	}
	return (0);
}
