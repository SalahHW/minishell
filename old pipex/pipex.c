/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:09:15 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/20 09:39:01 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_t_struc(t_pipex *a)
{
	a->f1 = NULL;
	a->f2 = NULL;
	a->len = 0;
	a->nbr_p = 0;
	a->path = NULL;
	a->lst = NULL;
}

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

int	main(int ac, char **av, char **env)
{
	t_pipex	*cmd;

	cmd = malloc(sizeof(t_pipex));
	ft_valid_av(ac, av, cmd);
	ft_init_t_struc(cmd);
	ft_arg_to_cmd(ac, av, env, cmd);
	cmd->len = ft_lst_len(cmd);
	if (cmd->len == 2)
		ft_fork(cmd, ac - 3, cmd->len);
	else
		ft_fork(cmd, ac - 3, ac - 3);
	ft_fc(cmd);
	ft_free(cmd);
	return (0);
}
