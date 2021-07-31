/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sender.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:48:30 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/31 21:00:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

/*
**	Sends a zero to the given pid
*/
void ft_send_zero(int pid)
{
	kill(pid, SIGUSR1);
	write(1, "0", 1);
}

/*
**	Sends a one to the given pid
*/
void ft_send_one(int pid)
{
	kill(pid, SIGUSR2);
	write(1, "1", 1);
}