/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:29 by jfritz            #+#    #+#             */
/*   Updated: 2021/08/01 10:23:40 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

/*
**	Converts binary number to decimal number
*/
int ft_bin_to_dec(long long n) {
    int dec;
	int i;
	int remainder;
	
	dec = 0;
	i = 0;
    while (n != 0) 
	{
        remainder = n % 10;
        n /= 10;
        dec += remainder * ft_recursive_power(2, i);
        i++;
    }
    return dec;
}

/*
**	Takes all incoming signals and sums then up to
**	8 bits, after that converts every 8 bits
**	to the correct char representation
*/
static void ft_sig_convert(int b)
{
	static int	counter = 0;
	static char	str[8];

	str[counter] = ft_itoa(b)[0];
	counter++;
	if (counter == 8)
	{
		counter = 0;
		int cd = ft_bin_to_dec(ft_atoi(str));
		write(1, &cd, 1);
	}
}

static void ft_zero()
{
	ft_sig_convert(0);
}

static void ft_one()
{
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