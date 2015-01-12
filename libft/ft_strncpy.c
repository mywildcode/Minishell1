/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:15:26 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/05 11:00:47 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				test;

	i = 0;
	test = 0;
	while (i != n)
	{
		if (src[i] == '\0')
			test = 1;
		if (test == 0)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	return (dest);
}
