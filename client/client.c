/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:33 by jfritz            #+#    #+#             */
/*   Updated: 2021/08/03 08:20:46 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>

/*
**	Validates PID
**
**	Returns true if pid is valid
*/
static int	ft_validate_pid(char *pid)
{
	int	count;

	count = 0;
	if (pid && (pid > 0))
	{
		while (pid[count])
		{
			if (!ft_isdigit(pid[count]))
				return (0);
			count++;
		}
		return (1);
	}
	return (0);
}

/*
**	Sends a signal for a given bit on given a char
*/
static void	ft_send_signal(char str_c, int pid, int *i2)
{
	if ((str_c >> (*i2)) & 1)
		ft_send_one(pid);
	else
		ft_send_zero(pid);
	(*i2)--;
}

/*
**	Simply sends over every char
**	Will call ft_char_to_bit for every
**	char until \0 and every ack signal received
**	Use bitshifting to see which
**	bit is at which position.
**	Then send the appropiate signal
*/
void	ft_iterate_over_str(char *str_d, int pid_d)
{
	static int	i;
	static char	*str;
	static int	pid;
	static int	i2;

	if (str_d)
	{
		i = 0;
		i2 = 7;
		str = str_d;
		pid = pid_d;
	}
	if (str[i])
	{
		if (i2 >= 0)
			ft_send_signal(str[i], pid, &i2);
		if (i2 < 0)
		{
			i2 = 7;
			i++;
		}
	}
	else
		exit(0);
}

static void	ft_ack_signal(int a)
{
	a = 1;
	usleep(37);
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
	char				*send;
	int					pid;
	struct sigaction	ack_action;

	if (argc == 3)
	{
		if (ft_validate_pid(argv[1]))
		{
			ack_action.sa_handler = ft_ack_signal;
			sigemptyset(&ack_action.sa_mask);
			sigaction (SIGUSR1, &ack_action, NULL);
			sigaction (SIGUSR2, &ack_action, NULL);
			pid = ft_atoi(argv[1]);
			send = argv[2];
			ft_iterate_over_str(send, pid);
			while (1)
				pause();
		}
	}
	return (0);
}
