/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:13:58 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/11 12:12:49 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_create_list(t_token *token, t_exec *new)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		ft_execadd_back(new, ft_new_execlist_node(tmp));
		tmp = tmp->next;
	}
	return (0);
}

void	ft_update(t_execlist *node, char *cmd_p, char **arg, int in_fd,
		int out_fd)
{
	node->cmd_path = ft_strdup(cmd_p);
	node->arg = ft_tab_copy(arg);
	node->fd_in = in_fd;
	node->fd_out = out_fd;
}

t_execlist	*ft_test(void)
{
	t_execlist	*one;
	t_execlist	*two;
	char		**arg;
	char		*cmd_p;

	cmd_p = ft_strdup("/bin/ls");
	arg = malloc(sizeof(char *) * 3);
	arg[0] = ft_strdup("ls");
	arg[1] = ft_strdup("-l");
	arg[2] = NULL;
	two = malloc(sizeof(t_execlist));
	one = malloc(sizeof(t_execlist));
	if (!one || !two)
		return (NULL);
	one->cmd_path = NULL;
	one->arg = NULL;
	one->fd_in = 0;
	one->fd_out = 0;
	one->next = two;
	one->prev = NULL;
	ft_update(one, cmd_p, arg, 0, 0);
	two->cmd_path = NULL;
	two->arg = NULL;
	two->fd_in = 0;
	two->fd_out = 0;
	two->next = NULL;
	two->prev = one;
	free(cmd_p);
	free_tab(arg);
	cmd_p = ft_strdup(""
	arg = malloc(sizeof(char *) * 3);
	arg[0] = ft_strdup("ls");
	arg[1] = ft_strdup("-l");
	arg[2] = NULL;
	ft_update(two, cmd_p, arg, 0, 0);
	return (one);
}

int	ft_create_struct(t_exec *exec, t_shell *shell)
{
	exec->general = shell->general;
	exec->execlist = ft_test();
	return (0);
}