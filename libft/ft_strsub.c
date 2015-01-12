/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:54:57 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/10 20:26:46 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		a;
	int		b;
	size_t	i;

	str = (char *)malloc(sizeof(*str) * (len + 1));
	a = 0;
	b = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[a] = s[start + b];
		a++;
		b++;
		i++;
	}
	str[a] = '\0';
	return (str);
}
