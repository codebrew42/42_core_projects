/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_call_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:29:31 by jiepark           #+#    #+#             */
/*   Updated: 2025/04/29 15:29:32 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"

static void	move_int_until_char(int *i, int len, char *arg, int c);
int			append_segment(char **current_result_ptr, char *segment);
char		*expand_var_rm_qot(t_mshell *data, char *original_arg, int f_hdc);

static void	move_int_until_char(int *i, int len, char *arg, int c)
{
	if (c == 0)
		while (*i < len && arg[*i] != '\'' && arg[*i] != '"')
			(*i)++;
	else
		while (*i < len && arg[*i] != c)
			(*i)++;
}

/**
 *@brief Append a segment to the *current_result_ptr
 *@return 1 on error, 0 on success
*/
int	append_segment(char **current_result_ptr, char *segment)
{
	char	*old_result;
	char	*new_result;

	if (!segment)
		return (0);
	if (!*current_result_ptr)
		return (free(segment), 1);
	old_result = *current_result_ptr;
	new_result = ft_strjoin(old_result, segment);
	free(old_result);
	free(segment);
	if (!new_result)
		return (1);
	*current_result_ptr = new_result;
	return (0);
}

int	process_quoted_and_var_exp(t_mshell *data, char *arg, int *i, char **p_res)
{
	int		first_quote;
	int		start;
	char	*raw_segment;
	char	*processed_segment;

	first_quote = arg[*i];
	(*i)++;
	start = *i;
	move_int_until_char(i, ft_strlen(arg), arg, first_quote);
	raw_segment = ft_substr(arg, start, *i - start);
	if (!raw_segment)
		return (1);
	if (first_quote == '"')
	{
		processed_segment = ev_expander(data, raw_segment);
		if (!processed_segment)
			return (1);
	}
	else
		processed_segment = raw_segment;
	if (append_segment(p_res, processed_segment) == 1)
		return (1);
	if (arg[*i] == first_quote)
		(*i)++;
	return (0);
}

static int	process_unquoted(t_mshell *data, char *arg, int *i, char **p_res)
{
	int		start;
	char	*raw_segment;
	char	*processed_segment;

	start = *i;
	move_int_until_char(i, ft_strlen(arg), arg, 0);
	raw_segment = ft_substr(arg, start, *i - start);
	if (!raw_segment)
		return (1);
	processed_segment = ev_expander(data, raw_segment);
	if (!processed_segment)
		return (1);
	if (append_segment(p_res, processed_segment) == 1)
		return (1);
	return (0);
}

/**
 *@brief Expand variables and remove quotes from the argument
 *@return a newly allocated string with result, or NULL on error
 */
char	*expand_var_rm_qot(t_mshell *data, char *original_arg, int f_hdc)
{
	int		i;
	char	*res;
	int		flag;

	if (!original_arg)
		return (ft_strdup(""));
	res = ft_strdup("");
	if (!res)
		return (NULL);
	i = 0;
	flag = 0;
	while (!f_hdc && original_arg[i] && flag == 0)
	{
		if (original_arg[i] == '"' || original_arg[i] == '\'')
			flag = process_quoted_and_var_exp(data, original_arg, &i, &res);
		else
			flag = process_unquoted(data, original_arg, &i, &res);
	}
	if (f_hdc)
		flag = process_hdc_args_quotes(original_arg, &res);
	if (flag == 1)
		return (free(res), NULL);
	return (res);
}
