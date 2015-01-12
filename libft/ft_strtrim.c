/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:27:32 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/13 11:31:35 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i2;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	i2 = ft_strlen(s) - 1;
	while (i2 > 0 && s[i2] && (s[i2] == ' ' || s[i2] == '\n' || s[i2] == '\t'))
		i2--;
	return (ft_strsub(s, 0, i2 + 1));
}
