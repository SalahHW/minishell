/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:37:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/20 09:41:01 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execute_cmd(t_pipex *cmd)
{
	if (execve(cmd->lst->cmd, cmd->lst->arv, NULL) == -1)
		return (-1);
	return (0);
}

int	ft_child_process(t_pipex *cmd, int **pipes, int i)
{
	if (i > 0)
		redir_input(pipes[i][0], cmd);
	else
		redir_input(cmd->f1->fd, cmd);
	if (i < cmd->len - 1)
		redir_output(pipes[i + 1][1], cmd);
	else
		redir_output(cmd->f2->fd, cmd);
	close_pipes(cmd->len - 1, pipes, i);
	if (ft_execute_cmd(cmd) == -1)
		return (-1);
	return (0);
}

void	ft_parent_process(t_pipex *cmd, int nbpipes, int **pipes, int nbprocess)
{
	int	i;
	int	status;

	i = 0;
	close(cmd->f1->fd);
	close(cmd->f2->fd);
	close_mpipes(nbpipes, pipes, nbprocess);
	while (i < nbprocess)
	{
		waitpid(-1, &status, 0);
		i++;
	}
}

void	ft_free_list0(t_lst *lst)
{
	int		i;
	t_lst	*tmp;
	t_lst	*tmp2;

	i = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			i = 0;
			tmp2 = tmp->next;
			while (tmp->arv[i] != NULL)
			{
				free(tmp->arv[i]);
				i++;
			}
			free(tmp->arv);
			free(tmp);
			tmp = tmp2;
		}
	}
}

void	ft_f(t_pipex *cmd)
{
	int	i;

	i = 0;
	ft_printf("open input failed");
	ft_fc(cmd);
	ft_free_list0(cmd->lst);
	while (cmd->path[i])
	{
		free(cmd->path[i]);
		i++;
	}
	free(cmd->path);
	free(cmd->f1);
	free(cmd->f2);
	free(cmd);
	exit(1);
}
