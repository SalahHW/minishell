/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:41:21 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/27 11:19:35 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_after(const char *s, int c)
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
		result = result + i + 1;
		return (result);
	}
	return (NULL);
}

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
		return (result);
	}
	return (NULL);
}

char	*ft_search_var_in_env(char **env, char *search, int need)
{
	int i;

	// need /0 == BEFORE/ /1 == ALL/ /2 = AFTER/ =
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(search, env[i], ft_strlen(search)) == 0)
		{
			// printf("env[%d]: %s for need = %d\n",i, env[i],need);
			if (need == 0)
				return (ft_before(env[i], '='));
			else if (need == 1)
				return (env[i]);
			else if (need == 2)
				return (ft_after(env[i], '='));
		}
		i++;
	}
	return (NULL);
}