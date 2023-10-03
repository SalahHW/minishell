/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:26:16 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 08:58:57 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

ft_child_process(char *cmd, char **arg,t_mini *mini)
{
    char *tmp;

    tmp = ft_path(mini->path,arg);
    if(tmp == NULL)
        return (1);
    if (execve(tmp, arg, mini->env) == -1)
        return (1);
    return (0);
}