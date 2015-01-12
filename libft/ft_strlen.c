/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:36:25 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/11 19:07:57 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[0] != '\0')
	{
		str++;
		i++;
	}
	return (i);
}
