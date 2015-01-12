/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:56:05 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/11 18:25:46 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ptr = (s + i);
		i++;
	}
	if (s[i] == '\0' && s[i] != (char)c)
		return ((char*)ptr);
	else if (s[i] == '\0' && s[i] == (char)c)
	{
		ptr = (s + i);
		return ((char*)ptr);
	}
	return (NULL);
}
