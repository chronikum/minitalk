/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:29 by jfritz            #+#    #+#             */
/*   Updated: 2021/08/01 09:57:25 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

static void ft_sig_convert(int b)
{
	static int	counter = 0;
	// static char	str[8];
	if (counter == 7)
	{
		// printf("%s\n", str);
		counter = 0;
	}
	// str[counter] = ft_itoa(b)[0];
	counter++;
	// printf("%d", b);
	ft_putnbr_fd(b, 1);
}

static void ft_zero()
{
    // write(1, "0", 1);
	ft_sig_convert(0);
}

static void ft_one()
{
    // write(1, "1", 1);
	ft_sig_convert(1);
}

int	main()
{
	pid_t pid;

	pid = getpid();

	ft_putnbr_fd((int) pid, 1);
	signal(SIGUSR1, ft_zero);
	signal(SIGUSR2, ft_one);
	while (1)
	{

	}
	return (0);
}