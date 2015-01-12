/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:31:43 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/12 14:23:08 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_itoa_max(char *str)
{
	int			n;
	int			i;

	n = 2147483647;
	i = 11;
	str = (char *)malloc(sizeof(char) * i);
	str[0] = '-';
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	str[10]++;
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		temp;

	i = (n > 0) ? 0 : 1;
	str = (char *)malloc(sizeof(char) * i);
	if (n == -2147483648)
		return (ft_itoa_max(str));
	temp = n;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	str[0] = (n >= 0) ? '0' : '-';
	str[i--] = '\0';
	n = (n < 0) ? -n : n;
	while (n != 0)
	{
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}
