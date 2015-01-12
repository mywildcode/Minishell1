/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:04:27 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/11 18:21:36 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		a;
	int		b;
	int		d;

	a = 0;
	b = 0;
	d = 0;
	c = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		c[d] = s1[a];
		d++;
		a++;
	}
	while (s2[b] != '\0')
	{
		c[d] = s2[b];
		d++;
		b++;
	}
	c[d] = '\0';
	return (c);
}
