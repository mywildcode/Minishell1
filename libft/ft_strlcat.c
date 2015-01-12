/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:41:59 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/10 10:47:54 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (size != 0 && *(dst + dest_len) != '\0')
	{
		dest_len++;
		size--;
	}
	if (size == 0)
		return (dest_len + ft_strlen(src));
	while (*src != '\0')
	{
		if (size != 1)
		{
			*(dst + dest_len) = *src;
			dst++;
			size--;
		}
		src++;
		src_len++;
	}
	*(dst + dest_len) = '\0';
	return (dest_len + src_len);
}
