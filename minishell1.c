/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:16:41 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/18 20:39:34 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

void	ft_prompt(char **line)
{
	ft_putstr("minishell> ");
	get_next_line(0, line);
}

int		ft_isspace(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	char	**str;
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	e->envcpy = env;
	if (argc == 1 && argv[0] != NULL)
	{
		while (42)
		{
			line = NULL;
			while ((line == NULL) || (line[0] == '\0'))
				ft_prompt(&line);
			if (ft_isspace(line) == 0)
			{
				str = ft_strsplit(line, ' ');
				control(str, e->envcpy, line, e);
			}
		}
	}
	return (0);
}
