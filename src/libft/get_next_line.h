/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:27:38 by aherrman          #+#    #+#             */
/*   Updated: 2023/06/02 14:17:41 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//*****lib*****//
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
//*****STRUCT*****//

typedef struct s_gnl
{
	char			*content;
	struct s_gnl	*next;
}	t_gnl;

//*****proto*****//
char	*get_next_line(int fd);
void	ft_read_and_stash(int fd, t_gnl **stash);
int		ft_add_to_stash(t_gnl **stash, char *buf, int size, int i);
void	ft_extract_line(t_gnl *stash, char **line);
int		ft_clean_stash(t_gnl **stash, int i, int j, t_gnl *lc[2]);
int		ft_found_newline(t_gnl *stash);
t_gnl	*ft_lst_get_last(t_gnl *stash);
void	ft_generate_line(char **line, t_gnl *stash);
int		ft_free_stash_or_len(t_gnl **stash, char *s, int select);
#endif
