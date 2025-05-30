/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:13:23 by                   #+#    #+#             */
/*   Updated: 2025/04/10 17:15:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_mshell	t_mshell;
typedef struct s_env	t_env;
typedef struct s_cmd	t_cmd;

int		ms_pwd(t_env *env);
char	*get_working_dir(t_env *env);
int		ms_cd(t_env **env, char **args);
int		ms_echo(char **av);
int		ms_env(t_env *env);
int		ms_exit(t_mshell *data, t_cmd *cmd_root, t_cmd *cmd, int *std);
int		ms_export(t_mshell *data, char **args);
int		ms_unset(t_mshell *data, char **av);

//utils
t_env	*search_env_name(t_env *env, char *name);
char	*get_env_val(t_env *env, char *name);
int		set_env_val(t_env *env, char *name, char *val);
void	lst_add_env(t_env **env, t_env *node);
void	lst_rm_env(t_env **env, t_env *to_remv);

//utils2
int		count_args(char **args);
int		is_symlink(char *cwd, char *link);
char	*get_fullpath(t_env *env, char *path);
char	*create_fullp(t_env *env, char *file, int dot);
int		add_cwd_path(t_env *env, char **args, int dot);

//utils3
int		set_env_oldpwd(t_env **env);
int		set_env_pwd(t_env **env, char *path);
int		no_alpha_name(char *s);
int		spchar_in_name(char *s);
#endif
