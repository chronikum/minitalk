/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:35:22 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 14:49:24 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	l;
	int				start;
	int				end;
	char			*r;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	l = ft_strlen(s1);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (ft_inset(s1[start], set) == 1)
	{
		start++;
		l--;
	}
	while (ft_inset(s1[end - 1], set) == 1)
	{
		end--;
		l--;
	}
	r = ft_substr(s1, start, l);
	return (r);
}
