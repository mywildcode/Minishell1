/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:17:15 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/11 19:12:53 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	y;

	if (ft_strlen(s2) == 0)
	{
		return ((char *)s1);
	}
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[0])
		{
			y = 1;
			while (s2[y] == s1[i + y] && (y + i) < n)
			{
				y++;
			}
			if (s2[y] == '\0')
			{
				return (&(((char *)s1)[i]));
			}
		}
		i++;
	}
	return (NULL);
}
