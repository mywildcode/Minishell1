/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:16:41 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/13 17:42:04 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int		main(int argc, char **argv, char **env)
{
	char	*line;
	char	**str;
	t_env	*e;

	argc = argc;
	argv = argv;
	e = (t_env *)malloc(sizeof(t_env));
	e->envcpy = env;
	while (42)
	{
		ft_putstr("minishell> ");
		line = get_next_line(0);
		str = ft_strsplit(line, ' ');
		control(str, e->envcpy, line, e);
	}
	return (0);
}
