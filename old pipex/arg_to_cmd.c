/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:54:11 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/20 09:45:30 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_test_access(t_pipex *cmd)
{
	t_temp	temp;
	t_lst	*a;

	temp.i.t2 = 0;
	temp.i.t0 = 0;
	a = cmd->lst;
	while (ft_lst_len(cmd) > temp.i.t0)
	{
		temp.i.t1 = 0;
		while (cmd->path[temp.i.t1])
		{
			temp.s.s0 = ft_strjoin(cmd->path[temp.i.t1], a->arv[0]);
			if (access(temp.s.s0, X_OK) == 0)
			{
				a->cmd = ft_strjoin(cmd->path[temp.i.t1], a->arv[0]);
				temp.i.t2++;
			}
			temp.i.t1++;
			free(temp.s.s0);
		}
		a = a->next;
		temp.i.t0++;
	}
	if (temp.i.t2 != temp.i.t0)
		ft_free_access(a, cmd);
}

void	ft_path(char **env, t_pipex *cmd, char **av, int ac)
{
	int		i;
	char	*temp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			cmd->path = ft_split(env[i] + 5, ':');
		}
		i++;
	}
	i = 0;
	while (cmd->path[i])
	{
		temp = cmd->path[i];
		cmd->path[i] = ft_strjoin(cmd->path[i], "/");
		free(temp);
		i++;
	}
	cmd->f1 = malloc(sizeof(t_file));
	cmd->f2 = malloc(sizeof(t_file));
	cmd->f1->file = av[1];
	cmd->f2->file = av[ac - 1];
}

int	tablenbr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_list(int ac, char **av, t_pipex *cmd)
{
	int		i;
	int		j;
	char	**str;

	i = 2;
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		ft_lstadd_back_pipex(cmd, ft_new_elem_pipex(str, str[0]));
		j = 0;
		while (str[j])
		{
			free(str[j]);
			j++;
		}
		free(str);
		i++;
	}
	ft_del_last(cmd);
}

void	ft_arg_to_cmd(int ac, char **av, char **env, t_pipex *cmd)
{
	char	*tmp;

	ft_list(ac, av, cmd);
	ft_path(env, cmd, av, ac);
	tmp = ft_strjoin("files/", cmd->f1->file);
	cmd->f1->fd = open(tmp, O_RDONLY | O_DIRECTORY);
	if (cmd->f1->fd == -1)
	{
		cmd->f1->fd = open(tmp, O_RDONLY);
		if (cmd->f1->fd < 0)
		{
			free(tmp);
			ft_f(cmd);
		}
	}
	else
	{
		free(tmp);
		ft_f(cmd);
	}
	free(tmp);
	ft_op(cmd);
	ft_test_access(cmd);
}
