/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:45:01 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 04:45:46 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Initialize the environement environement_list
t_envlist	*init_environement_list(void)
{
	t_envlist	*envlist;

	envlist = malloc(sizeof(t_envlist));
	envlist->head = NULL;
	envlist->tail = NULL;
	return (envlist);
}

// Add a new variable to the environement list
void	add_new_var(t_envlist *envlist, char *varname, char *varvalue)
{
	t_env	*new_var;

	new_var = malloc(sizeof(t_env));
	if (!new_var)
	{
		printf("Error while adding to environement\n");
		return ;
	}
	new_var->var_name = varname;
	new_var->var_value = varvalue;
	new_var->next = NULL;
	new_var->prev = envlist->tail;
	if (envlist->tail)
		envlist->tail->next = new_var;
	else
		envlist->head = new_var;
	envlist->tail = new_var;
}

// Delete a variable from the environement
void	delete_var(t_envlist *envlist, t_env *env_var)
{
	if (env_var->prev == NULL)
		envlist->head = env_var->next;
	else
		env_var->prev->next = env_var->next;
	if (env_var->next == NULL)
		envlist->tail = env_var->prev;
	else
		env_var->next->prev = env_var->prev;
	free(env_var->var_name);
	free(env_var->var_value);
	free(env_var);
}

void	clear_environement_list(t_envlist *envlist)
{
	t_env	*env_ptr;
	t_env	*next_var;

	env_ptr = envlist->head;
	while (env_ptr)
	{
		next_var = env_ptr->next;
		free(env_ptr->var_name);
		free(env_ptr->var_value);
		free(env_ptr);
		env_ptr = next_var;
	}
	free(envlist);
}

int	environement_list_size(t_envlist *envlist)
{
	t_env	*env_ptr;
	int		size;

	size = 0;
	env_ptr = envlist->head;
	while (env_ptr)
	{
		size++;
		env_ptr = env_ptr->next;
	}
	return (size);
}
