/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:44:36 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/13 17:05:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strjoin_free(char const *s1, char const **s2)
{
	char			*d;
	unsigned int	size;

	if (!s1 || !*s2)
		return (0);
	size = ft_strlen((char *) s1) + ft_strlen((char *) *s2) + 1;
	d = malloc(sizeof(char) * (size));
	if (!d)
		return (0);
	ft_memcpy(d, (const void *) s1, ft_strlen((char *) s1));
	ft_memcpy(&d[ft_strlen((char *) s1)], *s2, ft_strlen((char *) *s2));
	ft_memcpy(&d[ft_strlen((char *) s1)], *s2, ft_strlen((char *) *s2));
	ft_memcpy(&d[size - 1], "\0", 1);
	return (d);
}
