/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:46:37 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/12 20:49:37 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char	***ft_split_env(t_env *e, char c)
{
	int		i;
	char	***split_env;

	i = 0;
	split_env = (char ***)malloc(sizeof(char **) * 100);
	while (e->envcpy[i] != NULL)
	{
		split_env[i] = (char **)malloc(sizeof(char *) * 100);
		split_env[i] = ft_strsplit(e->envcpy[i], c);
		i++;
	}
	return (split_env);
}
