/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:49:37 by joakoeni          #+#    #+#             */
/*   Updated: 2023/10/02 16:34:35 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

#include "new.h"

int	ft_cd(char *arg, char **envp, char *home);
int	pwd(void);
int	pwd_change(t_mini *mini);
int unset(t_mini *mini,char **arg);
int	ft_export(t_mini *mini, char **arg);
int	env(char **env);

#endif
