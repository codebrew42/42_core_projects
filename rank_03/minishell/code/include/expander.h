/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:29:39 by jiepark           #+#    #+#             */
/*   Updated: 2025/05/03 16:38:23 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "builtins.h"

typedef struct s_env	t_env;

typedef struct s_quote_state
{
	size_t	i;
	size_t	j;
	char	active_quote;
}	t_quote_state;

typedef struct s_match_state {
	int	string_ptr;
	int	pattern_ptr;
	int	last_star_pos;
	int	string_pos_after_star;
}	t_match_state;

//exp_call_util.c
char	*expand_var_rm_qot(t_mshell *data, char *original_arg, int f_hdc);
int		append_segment(char **current_result_ptr, char *segment);

//exp_call_util2.c
int		replace_node_args(t_ast *node, t_list *new_list, char **original);
int		process_args(t_mshell *data, char **args, t_list **new_list, int f_hdc);
int		is_empty_quoted(char *arg);
int		process_hdc_args_quotes(char *arg, char **p_res);

//exp_call.c
int		handle_expansions_with_qots(t_mshell *data, t_ast *node);
char	**convert_list_to_array(t_list *list);
int		cnvt_arg(t_mshell *data, char *arg, t_list **new_list, int f_hdc);

//exp_ev_expander_utils.c
int		digit_key(char *key, char **envval);
int		count_linelen(t_list *lst);
char	*set_next_p(char *line);
int		check_dol_questn(char *key, char **envval, int excode);
char	*create_new_line(t_list *lst);

//exp_ev_expander.c
char	*ev_expander(t_mshell *data, char *line);

//exp_qot_check.c
int		ft_is_quote(char c);
int		has_nested_quotes(char *arg);
int		get_outer_quote_type(const char *str);

//exp_wc_expander_utils.c
int		filter_line(char *s, char *fil);
void	sort_args(char ***av);
void	swap_str(char **s1, char **s2);
int		ft_issorted(char *s1, char *s2);

//exp_wc_expander.c
char	**wc_expander(t_mshell *data, char *line);

#endif
