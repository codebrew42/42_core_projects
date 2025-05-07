/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:22:23 by jiepark           #+#    #+#             */
/*   Updated: 2025/04/25 13:22:23 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"

int			handle_expansions_with_qots(t_mshell *data, t_ast *node);
static int	has_unquoted_wc(char *arg);
static void	save_wc_results(char **wc_results, t_list **new_list);
int			cnvt_arg(t_mshell *data, char *arg, t_list **new_list, int f_hdc);
char		**convert_list_to_array(t_list *list);

int	handle_expansions_with_qots(t_mshell *data, t_ast *node)
{
	t_list	*new_arg_list;
	char	**original_args;
	int		f_hdc;

	if (!node || !(node->type == TYPE_CMD || is_redirection_type(node->type)))
		return (0);
	new_arg_list = NULL;
	original_args = node->args;
	f_hdc = 0;
	if (node->type == TYPE_REDIR_HDC)
		f_hdc = 1;
	if (process_args(data, original_args, &new_arg_list, f_hdc)
		|| replace_node_args(node, new_arg_list, original_args))
		return (1);
	if (node->right)
		return (handle_expansions_with_qots(data, node->right));
	return (0);
}

static int	has_unquoted_wc(char *arg)
{
	int	i;
	int	state;

	i = -1;
	state = UNQUOTED;
	while (arg[++i])
	{
		if (arg[i] == '*' && state == UNQUOTED)
			return (1);
		else if (arg[i] == '"')
		{
			if (state == UNQUOTED)
				state = DOUBLE_QUOTED;
			else if (state == DOUBLE_QUOTED)
				state = UNQUOTED;
		}
		else if (arg[i] == '\'')
		{
			if (state == UNQUOTED)
				state = SINGLE_QUOTED;
			else if (state == SINGLE_QUOTED)
				state = UNQUOTED;
		}
	}
	return (0);
}

static void	save_wc_results(char **wc_results, t_list **new_list)
{
	int		i;

	i = 0;
	while (wc_results[i])
	{
		ft_lstadd_back_content(new_list, wc_results[i]);
		wc_results[i] = NULL;
		i++;
	}
	free_strarr(wc_results);
	return ;
}

int	cnvt_arg(t_mshell *data, char *arg, t_list **new_list, int f_hdc)
{
	int		need_wc_expansion;
	char	*processed;
	char	**wc_results;
	int		arg_is_empty_quoted;

	need_wc_expansion = has_unquoted_wc(arg);
	arg_is_empty_quoted = is_empty_quoted(arg);
	processed = expand_var_rm_qot(data, arg, f_hdc);
	if (!processed)
		return (1);
	if (!arg_is_empty_quoted && processed[0] == '\0')
		return (free(processed), 0);
	wc_results = NULL;
	if (!f_hdc && need_wc_expansion && ft_strchr(processed, '*'))
		wc_results = wc_expander(data, processed);
	if (wc_results)
	{
		free(processed);
		save_wc_results(wc_results, new_list);
	}
	else
		ft_lstadd_back_content(new_list, processed);
	return (0);
}

char	**convert_list_to_array(t_list *list)
{
	char	**new_args_array;
	int		i;
	t_list	*current;

	new_args_array = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!new_args_array)
		return (NULL);
	i = 0;
	current = list;
	while (current)
	{
		new_args_array[i] = ft_strdup((char *)current->content);
		if (!new_args_array[i])
		{
			while (i-- > 0)
				free(new_args_array[i]);
			return (free(new_args_array), NULL);
		}
		current = current->next;
		i++;
	}
	new_args_array[i] = NULL;
	return (new_args_array);
}
