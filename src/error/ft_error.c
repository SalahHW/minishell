/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:06:19 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/29 10:12:26 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void ft_free(t_mini *mini)
{
    int i;

    i = 0;
    while (mini->env[i])
    {
        free(mini->env[i]);
        i++;
    }
    free(mini->env);
    i = 0;
    while (mini->expt[i])
    {
        free(mini->expt[i]);
        i++;
    }
    free(mini->expt);
    ft_free_list(mini->lst);
    free(mini);
}

void ft_print_error(char *str)
{
    ft_printf("minishell: %s\n", str);
}
