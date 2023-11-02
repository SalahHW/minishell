/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/11/02 09:27:55 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONEMENT_H
# define ENVIRONEMENT_H

typedef struct s_env
{
	char			*var_name;
	char			*var_value;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

typedef struct s_envlist
{
	t_env			*head;
	t_env			*tail;
}					t_envlist;

t_envlist			*init_environement_list(void);
void				add_new_var(t_envlist *envlist, char *varname,
						char *varvalue);
void				remove_var(t_envlist *envlist, char *varname);
void				delete_var(t_envlist *envlist, t_env *env_var);
void				clear_environement_list(t_envlist *envlist);
int					environement_list_size(t_envlist *envlist);

// Get the environement list from the environement variable
t_envlist			*get_parent_environement(char **envp);
// Search for a variable in the environement list by name
char				*get_var_value(t_envlist *envlist, char *varname);
// Convert the environement list to a char **
char				**environement_list_to_array(t_envlist *envlist);
char				*extract_varname(char *str);
char				*extract_varvalue(char *str);

#endif
