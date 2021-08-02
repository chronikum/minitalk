/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:29 by jfritz            #+#    #+#             */
/*   Updated: 2021/08/02 15:39:15 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

/*
**	Converts binary number to decimal number
*/
int	ft_bin_to_dec(long long n)
{
	int	dec;
	int	i;
	int	remainder;

	dec = 0;
	i = 0;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		dec += remainder * ft_recursive_power(2, i);
		i++;
	}
	return (dec);
}

/*
**	Takes all incoming signals and sums then up to
**	8 bits, after that converts every 8 bits
**	to the correct char representation
*/
static void	ft_sig_convert(int b)
{
	static int	counter = 0;
	static char	str[8];
	int			cd;

	str[counter] = b + '0';
	counter++;
	if (counter > 7)
	{
		counter = 0;
		cd = ft_bin_to_dec(ft_atoi(str));
		write(1, &cd, 1);
	}
}

static void ft_handle(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2)
		ft_sig_convert(1);
	else if (sig == SIGUSR1)
		ft_sig_convert(0);
	if (context)
		sig = 1;
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t	pid;
	struct sigaction zero_action;
	struct sigaction one_action;

	sigemptyset(&zero_action.sa_mask);
	sigemptyset(&one_action.sa_mask);
	zero_action.sa_sigaction = ft_handle;
	one_action.sa_sigaction = ft_handle;

	zero_action.sa_flags = 0x0040;
	one_action.sa_flags = 0x0040;
	pid = getpid();
	ft_putnbr_fd((int) pid, 1);
	sigaction (SIGUSR1, &zero_action, NULL);
	sigaction (SIGUSR2, &one_action, NULL);
	while (1)
		pause();
	return (0);
}
