/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_arg_of_cmd_and_hdc2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:18:36 by jiepark           #+#    #+#             */
/*   Updated: 2025/05/04 22:18:37 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_hdc_args_only(t_token *start);

int	count_hdc_args_only(t_token *start)
{
	int		hdc_args_count;
	t_token	*tmp;

	hdc_args_count = 0;
	tmp = start;
	while (tmp && is_hdc_or_tmp_word(tmp))
	{
		if (tmp->type == TYPE_TMP_WORD)
		{
			tmp = tmp->next;
		}
		if (tmp && tmp->type == TYPE_REDIR_HDC)
		{
			hdc_args_count++;
			tmp = tmp->next->next;
		}
	}
	return (hdc_args_count);
}
