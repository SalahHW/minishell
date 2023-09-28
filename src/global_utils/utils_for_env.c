/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:41:21 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/26 11:26:26 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_before(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	while (s[i] && s[i] != (char)c)
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		result = (char *)s;
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}

char	*ft_search_var_in_env(char *search, char **env, int need)
{
	int i;
	char *var;
	char *val;
	char *before;

	// need /0 == ALL/ /1 == before/ /2 = after/ =
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(search, env[i], ft_strlen(search)) == 0)
		{
			var = env[i];
			val = ft_strchr(var, '=');
			before = ft_before(var, '=');
			if (need == 0)
				return (before);
			else if (need == 1)
				return (var);
			else if (need == 2)
				return (val + 1);
		}
		i++;
	}
	return (NULL);
}