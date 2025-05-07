/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:51:38 by                   #+#    #+#             */
/*   Updated: 2025/05/05 21:00:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# define ERR -1

# include "builtins.h"
# include "heredoc.h"

typedef enum e_op
{
	OP_NONE,
	OP_PIPE,
	OP_OR,
	OP_AND,
}	t_op;

typedef enum e_bltin
{
	BI_NONE,
	BI_ECHO,
	BI_CD,
	BI_PWD,
	BI_EXPT,
	BI_UNSET,
	BI_ENV,
	BI_EXIT
}	t_bltin;

typedef enum e_type		t_type;
typedef struct s_mshell	t_mshell;

typedef struct s_rdct
{
	char			*path;
	t_type			type;
	int				fd;
	struct s_rdct	*next;
}	t_rdct;

typedef struct s_cmd
{
	char			*path;
	char			**args;
	t_bltin			bi;
	int				bi_only;
	t_op			op;
	t_type			type_rdct[2];
	char			*file_path[2];
	t_rdct			*files;
	int				fdin;
	int				fdout;
	int				pipe[2];
	int				paren[2];
	int				*pipe_prev[2];
	int				*pids;
	int				child;
	t_list			*old_files[2];
	struct s_cmd	*next;
}		t_cmd;

// executor.c
int		executor(t_mshell *data);
int		exec_cmds(t_mshell *data, t_cmd *cmds, int *pids);
int		create_subshell(t_mshell *data, t_cmd *cmds, t_cmd **tmp, int *pids);
int		create_cmdproc(t_mshell *data, t_cmd **cmd, t_cmd *cmd_root, int *pids);
void	wait_cmdproc(t_mshell *data, int *pids);

// exec_init.c
int		init_executor(t_mshell *data, t_cmd **cmds, int **pids);

// exec_stream.c
int		open_file(t_mshell *data, t_cmd *cmd, t_rdct *file);
int		create_pipe(t_cmd *cmd);
void	close_pstream(t_cmd *cmd);

// exec_cmdproc.c
int		cmd_proc(t_mshell *data, t_cmd *cmd, t_cmd *cmd_root);
int		set_cstream(t_cmd *cmd);
int		check_cmd(t_mshell *data, t_cmd *cmd, t_cmd *cmd_root);

// exec_builtin.c
int		exec_builtin(t_mshell *data, t_cmd *cmd, t_cmd *cmd_root);
void	call_builtin(t_mshell *data, t_cmd *cmd, t_cmd *cmd_root, int *std);
void	exit_builtin(t_mshell *data, t_cmd *cmd, t_cmd *cmd_root, int *std);
void	exit_exec(t_mshell *data, t_cmd *cmd);
t_bltin	isbuiltin(char *s);

// exec_free.c
void	free_cmdproc(t_mshell *data, t_cmd *cmd_root);
void	free_cmddata(t_cmd *cmd);
void	err_cmd(t_mshell *data, t_cmd *cmd_root, char *cmd);
void	exit_cmdproc(t_mshell *data, t_cmd *cmd_root, int excode);
void	free_rdct(t_rdct *node);

// exec_utils.c
int		count_cmd(t_ast *ast);
int		op_check(t_cmd **cmd, int *excode);
int		is_directory(char *path);
char	*create_pathstr(char *path, char *cmd);
void	set_excode(t_mshell *data, int code);

//utils2
int		set_stdinout(int from, int to);
int		count_cmdlst(t_cmd *cmd);
int		check_paren(t_ast *ast);
int		check_paren_syntx(t_ast *ast, int open, int close);
void	moveto_parenend(t_cmd **cmd);
//int		check_paren_with_op(t_ast *ast);

//utils3
void	free_prev_cmds(t_cmd **root, t_cmd **current);
void	set_flags(t_cmd **cmd, int *pids);

//test_utils
//void	testprint_cmds(t_cmd *cmd);
//void	testprint_rdct(t_rdct *node);

#endif
