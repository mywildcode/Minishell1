/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:46:37 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/14 11:22:31 by ql-eilde         ###   ########.fr       */
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

void	ft_execve_error(char **str)
{
	if (str[0][0] == '.' && str[0][1] != '/')
		ft_putendl_fd(ARGUMENTS, 2);
	else if (str[0][0] == '/' || (str[0][0] == '.' && str[0][1] == '/' &&
				str[0][2] == '\0'))
		ft_putstr_fd(PERMISSION, 2), ft_putendl_fd(str[0], 2);
	else if ((str[0][0] == '/' && str[0][1] != '\0') || (str[0][0] == '.' &&
			str[0][1] == '/' && str[0][2] != '\0'))
		ft_putstr_fd(NOSUCHFILE, 2), ft_putendl_fd(str[0], 2);
	else
		ft_putstr_fd(PERMISSION, 2), ft_putendl_fd(str[0], 2);
}

char	*ft_new_var(char **str)
{
	char	*var;

	if (str[1] != NULL && str[2] == NULL)
	{
		var = (char *)malloc(sizeof(var) * ft_strlen(str[1]) + 2);
		var = ft_strjoin(str[1], "=");
	}
	else
	{
		var = (char *)malloc(sizeof(var) * ft_strlen(str[1]) +
				ft_strlen(str[2]) + 2);
		var = ft_strjoin(ft_strjoin(str[1], "="), str[2]);
	}
	return (var);
}
