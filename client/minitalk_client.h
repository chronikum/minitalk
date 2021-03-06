/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:49:17 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/31 20:53:15 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include "../helper/minitalk_helper.h"
# include "../helper/libft/libft.h"

void	ft_send_zero(int pid);
void	ft_send_one(int pid);

#endif