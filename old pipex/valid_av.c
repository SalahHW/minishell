/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:29:38 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/20 09:40:37 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_list2(t_lst *lst)
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

void	ft_free_access(t_lst *a, t_pipex *cmd)
{
	int	i;

	i = 0;
	ft_printf("some av are not correct");
	ft_free_list(a);
	ft_fc(cmd);
	ft_free_list2(cmd->lst);
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

void	ft_first_free(char *s, t_pipex *cmd)
{
	ft_printf("%s\n", s);
	free(cmd);
	exit(1);
}

void	ft_valid_av(int ac, char **av, t_pipex *cmd)
{
	int	fd;

	fd = 1;
	if (ac < 5)
		ft_first_free("less 5 arguments in av", cmd);
	while (av[fd])
	{
		if (av[fd][0] == '\0')
			break ;
		fd++;
	}
	if (fd != ac)
		ft_first_free("some av are empty", cmd);
	open(av[1], fd);
	if (fd < 0)
		ft_first_free("files no found", cmd);
}

void	ft_op(t_pipex *cmd)
{
	char	*tmp;

	tmp = ft_strjoin("files/", cmd->f2->file);
	cmd->f2->fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (cmd->f2->fd == -1)
	{
		free(tmp);
		ft_error("open result failed", cmd);
	}
	free(tmp);
}
