/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:27:28 by aherrman          #+#    #+#             */
/*   Updated: 2023/06/13 10:49:58 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		ft_free_stash_or_len(&stash, NULL, 0);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	ft_read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	ft_extract_line(stash, &line);
	ft_clean_stash(&stash, 0, 0, (t_gnl *[2]){NULL, NULL});
	if (!line || line[0] == '\0')
	{
		ft_free_stash_or_len(&stash, NULL, 0);
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read_and_stash(int fd, t_gnl **stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (!ft_found_newline(*stash) && i != 0)
	{
		i = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && i == 0) || i == -1)
			return ;
		buf[i] = '\0';
		ft_add_to_stash(stash, buf, i, -1);
		if (*stash == NULL)
			return ;
	}
}

int	ft_add_to_stash(t_gnl **stash, char *buf, int size, int i)
{
	t_gnl	*last;
	t_gnl	*new_node;

	new_node = malloc(sizeof(t_gnl));
	if (new_node == NULL)
		return (ft_free_stash_or_len(stash, NULL, 0));
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (size + 1));
	if (new_node->content == NULL)
	{
		free(new_node);
		return (ft_free_stash_or_len(stash, NULL, 0));
	}
	while (buf[++i] && i < size)
		new_node->content[i] = buf[i];
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return (0);
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
	return (0);
}

void	ft_extract_line(t_gnl *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	ft_generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

int	ft_clean_stash(t_gnl **stash, int i, int j, t_gnl *lc[2])
{
	lc[1] = malloc(sizeof(t_gnl));
	if (stash == NULL || lc[1] == NULL)
	{
		free(lc[1]);
		return (ft_free_stash_or_len(stash, NULL, 0));
	}
	lc[1]->next = NULL;
	lc[0] = ft_lst_get_last(*stash);
	while (lc[0]->content[i] && lc[0]->content[i] != '\n')
		i++;
	if (lc[0]->content && lc[0]->content[i] == '\n')
		i++;
	lc[1]->content = malloc(sizeof(char) * (
				(ft_free_stash_or_len(NULL, lc[0]->content, 1) - i) + 1));
	if (lc[1]->content == NULL)
	{
		free(lc[1]);
		return (ft_free_stash_or_len(stash, NULL, 0));
	}
	while (lc[0]->content[i])
		lc[1]->content[j++] = lc[0]->content[i++];
	lc[1]->content[j] = '\0';
	ft_free_stash_or_len(stash, NULL, 0);
	*stash = lc[1];
	return (0);
}
