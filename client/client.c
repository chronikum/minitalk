/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:33 by jfritz            #+#    #+#             */
/*   Updated: 2021/08/01 10:22:05 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>

/*
**	Use bitshifting to see which
**	bit is at which position.
**	Then send the appropiate signal
*/
void	ft_char_to_bit(char c, int pid, int *sentBytes)
{
	int i;
	static int sent = 0;
	
	i = 7;
	while(i >= 0)
    {
		usleep(40);
		if ((c >> i) & 0x01)
			ft_send_one(pid);
		else
			ft_send_zero(pid);
		i--;
		sent++;
		(*sentBytes) = sent;
	}
}

/*
**	Simply iterates over every char
**	Will call ft_char_to_bit for every
**	char until \0
*/
void ft_iterate_over_str(char *str, int pid)
{
	int i;
	int *sentBytes;
	sentBytes = malloc(sizeof(int *));
	i = 0;	
	while (str[i])
	{
		ft_char_to_bit(str[i], pid, sentBytes);
		i++;
	}
	printf("\n%d sent bits", (*sentBytes));
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

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send = argv[2];
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		// ft_putstr_fd(send, 1);
		ft_iterate_over_str(send, pid);
	}
	return (0);
}