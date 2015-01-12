/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:11:19 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/06 18:52:15 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*p1;
	size_t			i;

	p1 = (unsigned char *)d;
	i = 0;
	while (i < len)
	{
		p1[i] = c;
		i++;
	}
	return (d);
}
