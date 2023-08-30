/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:41:12 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/19 16:07:47 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_list(t_lst *lst)
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
			if (tmp->cmd != NULL)
				free(tmp->cmd);
			free(tmp);
			tmp = tmp2;
		}
	}
}

void	ft_free2(t_pipex *cmd)
{
	free(cmd->f1);
	free(cmd->f2);
	free(cmd->path);
	free(cmd);
}

void	ft_free(t_pipex *cmd)
{
	int	i;

	i = 0;
	while (cmd->path[i])
	{
		free(cmd->path[i]);
		i++;
	}
	if (cmd->lst)
		ft_free_list(cmd->lst);
	ft_free2(cmd);
}

void	ft_error(char *str, t_pipex *cmd)
{
	if (!(str))
		ft_printf("unknow error\n");
	else
		ft_printf("%s\n", str);
	if (cmd)
		ft_free(cmd);
	exit(1);
}

void	ft_fc(t_pipex *cmd)
{
	if (!cmd->lst)
		return ;
	while ((cmd->lst)->prev)
		(cmd->lst) = (cmd->lst)->prev;
}
