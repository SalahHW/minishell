/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:28:56 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/07 05:05:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

typedef enum e_signal_status
{
	DEFAULT,
	READ,
	IGNORE,
}		t_signal_status;

void	signal_handlers(t_signal_status status);
void	handle_sigquit(int sig);
void	read_sig_handler(int sig);

#endif
