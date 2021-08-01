/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:29 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/31 21:34:37 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

static int ft_counter(int r)
{
	static int i = 0;
	if (r)
		i = 0;
	i++;
	return i;
}

static void ft_zero()
{
    write(1, "0", 1);
	ft_counter(0);
}

static void ft_one()
{
    write(1, "1", 1);
	ft_counter(0);
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