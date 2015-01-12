/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:11:38 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/10 18:52:11 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*srce;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	while (i < n)
	{
		dest[i] = srce[i];
		if (srce[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
