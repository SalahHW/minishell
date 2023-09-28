/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:23:01 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/27 15:25:12 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_H
# define NEW_H

typedef struct s_mini
{
	char	**env;
	char	**path;
	char 	**expt;
	char	*home;
}			t_mini;

// create env,path,home
void		ft_create_env_and_path(t_mini *mini, char **env);
void		ft_init_mini(t_mini *mini);
void		mini_free(t_mini *mini);

#endif
