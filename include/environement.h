/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:49:10 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/25 16:29:38 by sbouheni         ###   ########.fr       */
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
void				remove_var(t_envlist *envlist);
void				clear_environement_list(t_envlist *envlist);

t_envlist			*get_parent_environement(char **envp);

char				*extract_varname(char *str);
char				*extract_varvalue(char *str);

// Search for a variable in the environement list by name
char				*get_var_value(t_envlist *envlist, char *varname);

#endif
