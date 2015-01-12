/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:17:33 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/06 11:50:37 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		l;
	char	*cp;

	i = 0;
	l = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		cp = (char *)&str[i];
		while (str[i] == to_find[l] && to_find[l] != '\0')
		{
			i++;
			l++;
			if (to_find[l] == '\0')
				return ((char *)cp);
		}
		l = 0;
		i++;
	}
	return (0);
}
