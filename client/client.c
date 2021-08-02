/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:33 by jfritz            #+#    #+#             */
/*   Updated: 2021/08/02 11:19:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>

/*
**	Use bitshifting to see which
**	bit is at which position.
**	Then send the appropiate signal
*/
// void	ft_char_to_bit(char c, int pid)
// {
// 	int	i;

// 	i = 7;
// 	while (i >= 0)
// 	{
// 		usleep(75);
// 		ft_putnbr_fd(((c >> i) & 0x01), 1);
// 		if ((c >> i) & 0x01)
// 			ft_send_one(pid);
// 		else
// 			ft_send_zero(pid);
// 		i--;
// 	}
// }

/*
**	Simply sends over every char
**	Will call ft_char_to_bit for every
**	char until \0 and every ack signal received
*/
void	ft_iterate_over_str(char *str_d, int pid_d)
{
	static int	i;
	static char *str;
	static int	pid;
	static int	i2;

	if (str_d)
	{
		i = 0;
		i2 = 7;
		str = str_d;
		pid = pid_d;
		ft_putstr_fd("SETTING!", 1);
	}
	if (str[i])
	{
		if (str[i])
		{
			if (i2 >= 0)
			{
				ft_putnbr_fd(((str[i] >> i2) & 0x01), 1);
				ft_putstr_fd("\nSENDING BIT ", 1);
				ft_putnbr_fd(i2, 1);
				ft_putstr_fd(" of char: ", 1);
				ft_putchar_fd(str[i], 1);
				ft_putstr_fd("\n", 1);
				if ((str[i] >> i2) & 0x01)
					ft_send_one(pid);
				else
					ft_send_zero(pid);
				i2--;
			}
			if (i2 < 0)
			{
				i2 = 7;
				i++;
			}
		}
	}
}

static void	ft_ack_signal(int a)
{
	write(1, "SIGNAL!", 7);
	a = 1;
	ft_iterate_over_str(NULL, 0);
}

/*
**	Basic validation checking.
**	Also calling the iteration
**	function to iterate over
**	every char
*/
int	main(int argc, char *argv[])
{
	char	*send;
	int		pid;
	struct sigaction ack_action;

	if (argc == 3)
	{
		ack_action.sa_handler = ft_ack_signal;
		sigemptyset(&ack_action.sa_mask);
		// ack_action.sa_flags = 0;
		sigaction (SIGUSR1, &ack_action, NULL);
		sigaction (SIGUSR2, &ack_action, NULL);
		pid = ft_atoi(argv[1]);
		send = argv[2];
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		ft_iterate_over_str(send, pid);
		// ft_ack_signal(1);
		while (1)
			pause();
	}
	return (0);
}
