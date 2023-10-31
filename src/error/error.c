/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:15:08 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/31 13:33:35 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	write_error(char *cmd, char *input, int error_no)
{
	int		len;
	char	*err_str;

	write(STDERR_FILENO, "Minishell: ", 11);
	if (cmd != NULL)
	{
		len = ft_strlen(cmd);
		write(STDERR_FILENO, cmd, len);
		write(STDERR_FILENO, ": ", 2);
	}
	if (input != NULL)
	{
		len = ft_strlen(input);
		write(STDERR_FILENO, input, len);
		write(STDERR_FILENO, ": ", 2);
	}
	err_str = strerror(error_no);
	len = ft_strlen(err_str);
	write(STDERR_FILENO, err_str, len);
	write(STDERR_FILENO, "\n", 2);
}
void	write_preset_error(char *err, char *cmd)
{
	int	len;

	len = 0;
	write(STDERR_FILENO, "Minishell: ", 11);
	if (cmd != NULL)
	{
		len = ft_strlen(cmd);
		write(STDERR_FILENO, cmd, len);
		write(STDERR_FILENO, ": ", 2);
	}
	if (err != NULL)
	{
		len = ft_strlen(err);
		write(STDERR_FILENO, err, len);
		write(STDERR_FILENO, " \n", 2);
	}
}

int	error(char *cmd, char *input, int error)
{
	if (error == 0)
		return (error);
	else if (error == 1)
		write_preset_error("No such file or directory", cmd);
		else if (error == 2)
		write_preset_error("`=': not a valid identifier",cmd);
	else if (error == 127)
		write_preset_error("command not found", cmd);
	else
		write_error(cmd, input, error);
	return (errno);
}