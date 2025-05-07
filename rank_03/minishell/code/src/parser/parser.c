/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:31 by jiepark           #+#    #+#             */
/*   Updated: 2025/03/17 18:59:31 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				has_cmd_and_hdc(t_token *cur_tk);
static t_ast	*tk_to_ast(t_token **cur_tk, t_ast **cur_ast, t_ast **ast_root);
int				parser(t_token **tokens, t_ast **ast_root);

static void	init_values(int *hdc_flag, int *cmd_flag, int *total_arg_count)
{
	*hdc_flag = 0;
	*cmd_flag = 0;
	*total_arg_count = 0;
}

int	has_cmd_and_hdc(t_token *cur_tk)
{
	int		total_arg_count;
	int		hdc_flag;
	int		cmd_flag;

	init_values(&hdc_flag, &cmd_flag, &total_arg_count);
	while (cur_tk && is_hdc_or_tmp_word(cur_tk))
	{
		if (cur_tk->type == TYPE_REDIR_HDC)
		{
			hdc_flag = 1;
			if (cur_tk->next)
				cur_tk = cur_tk->next->next;
			else
				break ;
			total_arg_count++;
		}
		else if (cur_tk->type == TYPE_TMP_WORD)
		{
			cur_tk = cur_tk->next;
			cmd_flag = 1;
			total_arg_count++;
		}
	}
	return (hdc_flag && cmd_flag);
}

static t_ast	*tk_to_ast(t_token **cur_tk, t_ast **cur_ast, t_ast **ast_root)
{
	while (*cur_tk)
	{
		if (is_paren_type((*cur_tk)->type) || is_op_type((*cur_tk)->type))
			*cur_ast = save_an_arg_null(cur_tk, cur_ast, ast_root);
		else if (has_cmd_and_hdc(*cur_tk))
			*cur_ast = save_args_cmd_and_hdc(cur_tk, cur_ast, ast_root);
		else if (has_embedded_redirs(*cur_tk))
			*cur_ast = save_args_redirs(cur_tk, cur_ast, ast_root);
		else if (is_redir_not_hdc_type((*cur_tk)->type))
			*cur_ast = save_an_arg(cur_tk, cur_ast, ast_root);
		else
			*cur_ast = save_args(cur_tk, cur_ast, ast_root);
		if (!*cur_ast)
			return (NULL);
		if (*cur_tk)
			*cur_tk = (*cur_tk)->next;
	}
	return (*ast_root);
}

int	parser(t_token **tokens, t_ast **ast_root)
{
	t_token		*cur_tk;
	t_ast		*cur_ast;
	t_token		*head;

	if (!tokens || !*tokens || !ast_root)
		return (0);
	head = *tokens;
	cur_tk = head;
	cur_ast = NULL;
	*ast_root = NULL;
	if (!tk_to_ast(&cur_tk, &cur_ast, ast_root))
		return (*tokens = head, 0);
	*tokens = head;
	return (validate_ast(ast_root, tokens, head));
}
