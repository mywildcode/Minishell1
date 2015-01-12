/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:22:39 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/11 15:52:29 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define READ_MAX 5

int		len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_realloc(char *old, int size)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = malloc(sizeof(*new) * (len(old) + size))) == NULL)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

char	*get_next_line(const int fd)
{
	static int		lat = 1;
	static int		rd = 0;
	static int		i = 0;
	static char		*rs = NULL;
	static char		bf[READ_MAX];

	if (bf[len(bf) - rd] == '\0')
	{
		if ((rd = read(fd, bf, READ_MAX)) <= 0)
			return (rs = (lat-- && bf[len(bf) - rd - 1] != 10) ? rs : NULL);
		bf[rd] = '\0';
	}
	if ((rs = (i == 0) ? malloc(sizeof(*rs) * READ_MAX + 1) :
				ft_realloc(rs, sizeof(*rs) * READ_MAX + 1)) == NULL)
		return (NULL);
	while (bf[len(bf) - rd] && bf[len(bf) - rd] != '\n')
		rs[i++] = bf[len(bf) - rd--];
	rs[i] = '\0';
	if (bf[len(bf) - rd] == '\n')
	{
		i = 0;
		rd--;
		return (rs);
	}
	return (get_next_line(fd));
}
