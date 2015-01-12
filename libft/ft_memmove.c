/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:55:45 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/10 12:10:00 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	temp[len];
	char	*dest;
	char	*srce;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	while (i < len)
	{
		temp[i] = srce[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dest[i] = temp[i];
		i++;
	}
	return (dst);
}
