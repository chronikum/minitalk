/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sender_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:48:30 by jfritz            #+#    #+#             */
/*   Updated: 2021/08/03 08:25:02 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client_bonus.h"

/*
**	Sends a zero to the given pid
*/
void	ft_send_zero(int pid)
{
	kill(pid, SIGUSR1);
}

/*
**	Sends a one to the given pid
*/
void	ft_send_one(int pid)
{
	kill(pid, SIGUSR2);
}
