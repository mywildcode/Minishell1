/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:55:03 by ql-eilde          #+#    #+#             */
/*   Updated: 2015/01/13 19:12:30 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
# define MINISHELL1_H

# include "libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_env
{
	char		**envcpy;
}				t_env;

char			***ft_split_env(t_env *e, char c);
char			*get_next_line(const int fd);
char			*ft_getenv(char **env, char *elem);
char			**ft_getpaths(char *elem);
char			*verify_access(char **str, char **env);
void			execute_program(char *ok, char **str, char **env);
void			ft_executebin(char **str, char **env);
void			ft_cd(char **str, t_env *e);
void			ft_exit(void);
void			ft_env(t_env *e);
int				ft_len(t_env *e);
void			ft_setenv(t_env **e, char **str);
int				ft_setenv_modify(t_env *e, char **str);
void			ft_unsetenv(t_env *e, char **str);
int				is_builtin(char **str);
void			which_builtin(char **str, t_env *e);
void			control(char **str, char **env, char *line, t_env *e);
void			ft_execve_error(char **str);
char			*ft_new_var(char **str);

#endif
