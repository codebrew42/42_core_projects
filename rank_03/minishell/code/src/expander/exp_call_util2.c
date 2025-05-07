/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_call_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:30:50 by jiepark           #+#    #+#             */
/*   Updated: 2025/05/04 16:30:51 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"

int	replace_node_args(t_ast *node, t_list *new_list, char **original);
int	process_args(t_mshell *data, char **args, t_list **new_list, int f_hdc);
int	is_empty_quoted(char *arg);
int	process_hdc_args_quotes(char *arg, char **p_res);

int	process_args(t_mshell *data, char **args, t_list **new_list, int f_hdc)
{
	int	i;

	i = -1;
	while (args && args[++i])
	{
		if (cnvt_arg(data, args[i], new_list, f_hdc))
		{
			ft_lstclear(new_list, free);
			return (1);
		}
	}
	return (0);
}

int	replace_node_args(t_ast *node, t_list *new_list, char **original)
{
	char	**new_array;

	new_array = convert_list_to_array(new_list);
	ft_lstclear(&new_list, free);
	if (!new_array && ft_lstsize(new_list) > 0)
		return (1);
	free_strarr(original);
	node->args = new_array;
	return (0);
}

int	is_empty_quoted(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len < 2)
		return (0);
	return ((arg[0] == '"' && arg[1] == '"')
		|| (arg[0] == '\'' && arg[1] == '\''));
}

static int	remove_outer_quotes(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 2 && ((str[0] == '"' && str[len - 1] == '"')
			|| (str[0] == '\'' && str[len - 1] == '\'')))
	{
		ft_memmove(str, str + 1, len - 2);
		str[len - 2] = '\0';
		return (1);
	}
	return (0);
}

int	process_hdc_args_quotes(char *arg, char **p_res)
{
	char	*processed_segment;

	if (ft_strchr(arg, '"') || ft_strchr(arg, '\''))
	{
		processed_segment = ft_strdup(arg);
		if (!processed_segment)
			return (1);
		remove_outer_quotes(processed_segment);
		if (append_segment(p_res, processed_segment) == 1)
			return (1);
	}
	else
	{
		processed_segment = ft_strdup(arg);
		if (!processed_segment)
			return (1);
		if (append_segment(p_res, processed_segment) == 1)
			return (1);
	}
	return (0);
}
