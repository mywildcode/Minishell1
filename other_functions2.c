/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:35:02 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/12 20:53:16 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char	*verify_access(char **str, char **env)
{
	char	*perms;
	char	*cool;
	char	**paths;
	int		i;

	i = 0;
	perms = ft_strnew(1);
	paths = ft_getpaths(ft_getenv(env, "PATH"));
	while (paths[i] != NULL)
	{
		perms = ft_strjoin(ft_strjoin(perms, paths[i]), "/");
		perms = ft_strjoin(perms, str[0]);
		cool = perms, free(perms);
		if ((access(cool, R_OK)) == 0)
			return (cool);
		i++, ft_bzero(cool, 1);
	}
	return (NULL);
}

void	execute_program(char *ok, char **str, char **env)
{
	int		status;
	pid_t	pid;

	pid = fork();
	ok = ok;
	if (pid == 0)
	{
		if (execve(ok, str, env) == -1)
		{
			if (str[0][0] == '.' && str[0][1] != '/')
				ft_putendl(".: not enough arguments");
			else if (str[0][0] == '.' && str[0][1] == '/' && str[0][2] == '\0')
				ft_putendl("minishell: permission denied: ./");
			else
			{
				ft_putstr("minishell: Access not granted: ");
				ft_putendl(str[0]);
			}
		}
		exit(0);
	}
	if (pid > 0)
		wait(&status);
}

int		is_builtin(char **str)
{
	if ((ft_strcmp(str[0], "cd")) == 0 ||
			(ft_strcmp(str[0], "env")) == 0 ||
			(ft_strcmp(str[0], "setenv")) == 0 ||
			(ft_strcmp(str[0], "unsetenv")) == 0 ||
			(ft_strcmp(str[0], "exit")) == 0)
		return (1);
	return (0);
}

void	which_builtin(char **str, char **env, t_env *e)
{
	if (ft_strcmp(str[0], "cd") == 0)
		ft_cd(str, env);
	else if (ft_strcmp(str[0], "env") == 0)
		ft_env(e);
	else if (ft_strcmp(str[0], "setenv") == 0 &&
			ft_setenv_modify(e, str) != 1)
		ft_setenv(&e, str);
	else if (ft_strcmp(str[0], "unsetenv") == 0)
		ft_unsetenv(e, str);
	else if (ft_strcmp(str[0], "exit") == 0)
		ft_exit();
}

void	control(char **str, char **env, char *line, t_env *e)
{
	char	*ok;

	if ((ok = verify_access(str, env)) != NULL && (is_builtin(str)) != 1)
		execute_program(ok, str, env);
	else if (is_builtin(str) == 1)
		which_builtin(str, env, e);
	else if (str[0][0] == '.' && str[0][1] == '/')
		ft_executebin(str, env);
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(line);
	}
}
