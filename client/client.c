/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:33 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/30 13:48:26 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

void	ft_send_signal()
{

}

int	main(int argc, char *argv[])
{
	char	*send;
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send = argv[2];
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		ft_putstr_fd(send, 1);

		if (pid && send)
			kill(pid, SIGUSR1);
	}
	return (0);
}