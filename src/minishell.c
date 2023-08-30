/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:17:22 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/29 10:05:00 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_temp(t_temp *temp)
{
	temp->i.t0 = 0;
	temp->i.t1 = 0;
	temp->i.t2 = 0;
	temp->i.t3 = 0;
	temp->i.t4 = 0;
	temp->i.t5 = 0;
	temp->s.s0 = NULL;
	temp->s.s1 = NULL;
	temp->s.s2 = NULL;
	temp->s.s3 = NULL;
}
void ft_init_t_struct(t_mini *mini)
{
	mini->env = NULL;
	mini->expt = NULL;
	mini->lst = NULL;
}
int	main(int ac, char **av, char **env)
{
	if (ac != 1)
	ft_error("too many arguments");
		return (0);
		(void)av;
	t_mini *mini;

	mini = malloc(sizeof(t_mini));
	ft_init_t_struct(mini);
	ft_arg_to_mini(env, mini);
}