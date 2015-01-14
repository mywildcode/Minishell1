/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:30:06 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/14 13:50:10 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

void	ft_cd(char **str, t_env *e)
{
	char	*home;

	if (str[1] == NULL)
		home = ft_getenv(e->envcpy, "HOME"), chdir(home);
	else if (access(str[1], R_OK) == -1 || chdir(str[1]) != 0)
		ft_putstr_fd(CDERROR, 2), ft_putendl_fd(str[1], 2);
}

void	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_env(t_env *e)
{
	int		i;

	i = 0;
	while (e->envcpy[i] != NULL)
		ft_putendl(e->envcpy[i]), i++;
}

void	ft_setenv(t_env **e, char **str)
{
	char	**new_env;
	char	*tmp;
	int		j;
	int		a;

	j = 0;
	a = 0;
	new_env = (char **)malloc(sizeof(new_env) * ft_len(*e));
	while ((*e)->envcpy[j] != NULL)
		new_env[a] = (*e)->envcpy[j], a++, j++;
	tmp = ft_new_var(str);
	new_env[a] = ft_strdup(tmp);
	new_env[++a] = NULL;
	a = 0;
	while (new_env[a])
		(*e)->envcpy[a] = ft_strdup(new_env[a]), a++;
	free(tmp), free(new_env), (*e)->envcpy[a] = NULL;
}

void	ft_unsetenv(t_env *e, char **str)
{
	int		i;
	int		j;
	int		ret;
	char	***split;

	j = 1;
	split = ft_split_env(e, '=');
	while (str[j] != NULL)
	{
		i = 0;
		while (split[i] != NULL && (ret = ft_strcmp(split[i][0], str[1])) != 0)
			i++;
		if (ret == 0)
		{
			while (i < (ft_len(e) - 1))
				e->envcpy[i] = e->envcpy[i + 1], i++;
			e->envcpy[i] = NULL;
		}
		j++;
	}
}
