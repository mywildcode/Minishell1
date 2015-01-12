/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:45:30 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/12 12:37:38 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*srce;
	int		test;

	i = 0;
	test = 0;
	dest = (char *)dst;
	srce = (char *)src;
	while (i != n)
	{
		if (srce[i] == '\0')
			test = 1;
		if (test == 0)
			dest[i] = srce[i];
		else
			dest[i] = '\0';
		i++;
	}
	return (dst);
}
