/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:22:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/24 10:21:37 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//***** LIB *****//
# include "libft/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//*****STRUCT*****//
typedef struct s_lint
{
	long int		t0;
	long int		t1;
	long int		t2;
	long int		t3;
	long int		t4;
	long int		t5;
}					t_lint;

typedef struct s_string
{
	char			*s0;
	char			*s1;
	char			*s2;
	char			*s3;
}					t_string;

typedef struct s_temp
{
	t_lint			i;
	t_string		s;

}					t_temp;
typedef struct s_lst
{
	char			*cmd;
	char			*vpath;
	struct s_lst	*next;
}					t_lst;

typedef struct s_mini
{
	char **env;
	char **expt;
	char **path;
	t_lst *lst;

}					t_mini;

void ft_arg_to_mini(char **env, t_mini *mini);
#endif