/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:13:58 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/20 10:57:28 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/minishell.h"

// void	ft_update(t_execlist *node, char *cmd_p, char **arg, int in_fd,
// 		int out_fd)
// {
// 	if (cmd_p)
// 		node->cmd_path = ft_strdup(cmd_p);
// 	if (arg)
// 		node->arg = ft_tab_copy(arg);
// 	if (in_fd != -99)
// 		node->fd_in = in_fd;
// 	if (out_fd != -99)
// 		node->fd_out = out_fd;
// }

// t_execlist	*ft_test(void)
// {
// 	char		**arg;
// 	char		*cmd_p;
// 	int			f_in;
// 	int			f_out;
// 	t_execlist	*one;
// 	t_execlist	*two;

// 	f_in = -99;
// 	f_out = -99;
// 	cmd_p = ft_strdup("/bin/ls");
// 	arg = malloc(sizeof(char *) * 1);
// 	arg[0] = ft_strdup("ls");
// 	arg[1] = NULL;
// 	two = malloc(sizeof(t_execlist));
// 	one = malloc(sizeof(t_execlist));
// 	if (!one)
// 		return (NULL);
// 	one->cmd_path = NULL;
// 	one->arg = NULL;
// 	one->fd_in = -99;
// 	one->fd_out = -99;
// 	one->next = NULL;
// 	one->prev = NULL;
// 	ft_update(one, cmd_p, arg, f_in, f_out);
// 	if (cmd_p)
// 		free(cmd_p);
// 	if (arg)
// 		free_tab(arg);
// 	two->cmd_path = NULL;
// 	two->arg = NULL;
// 	two->fd_in = 0;
// 	two->fd_out = 0;
// 	two->next = NULL;
// 	two->prev = NULL;
// 	cmd_p = ft_strdup("/bin/cat");
// 	arg = malloc(sizeof(char *) * 3);
// 	arg[0] = ft_strdup("cat");
// 	arg[1] = ft_strdup("-e");
// 	arg[2] = NULL;
// 	f_in = -99;
// 	f_out = open("f1", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	ft_update(two, cmd_p, arg, f_in, f_out);
// 	if (cmd_p)
// 		free(cmd_p);
// 	if (arg)
// 		free_tab(arg);
// 	return (one);
// }
