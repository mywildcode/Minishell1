/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 15:27:40 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/11 18:00:43 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_nb_word(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				j++;
		}
	}
	return (j);
}

static char		**ft_stralloc(char const *s, char c, int i, int j)
{
	int		k;
	char	**strv;

	k = 0;
	strv = (char **)malloc(sizeof(char*) * ((ft_nb_word(s, c)) + 1));
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
			if (s[i] == c || s[i] == '\0')
			{
				strv[k] = (char *)malloc(sizeof(char) * (j + 1));
				k++;
				j = 0;
			}
		}
	}
	return (strv);
}

static char		**ft_filler(char **str, char const *s, char c, int i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			str[k][j] = (char)s[i];
			i++;
			j++;
			if (s[i] == c || s[i] == '\0')
			{
				str[k][j] = '\0';
				k++;
				j = 0;
			}
		}
	}
	str[k] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	return (ft_filler(ft_stralloc(s, c, 0, 0), s, c, 0));
}
