/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:11:24 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:11:25 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int					idx;
	int					is_upper_mid;
	int					val;
	int					cost;
	int					cost_is_cheapest;
	struct s_node		*left;
	struct s_node		*right;
	struct s_node		*target;
}	t_node;

//gnl
char			*ft_strjoin_free_param(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strndup(char *src, int nbr);
int				ft_strchr_idx(const char *s, int c);
char			*get_next_line(int fd);

//main_utils.c
int				handle_single_argument(char *argv, t_node **stack_a);
void			free_and_exit(t_node **stack, char **str, int free_arr);
int				free_stack_and_arr(t_node **stack, char **str, int free_arr);
void			free_stack_and_exit(t_node **stack);

//checker
int				is_valid_op(char *line);
void			free_arr_int(int *str);
int				read_and_execute_operation(t_node **stack_a, t_node **stack_b);
long			get_nbr(const char *str, int *len);
int				*tokenize_bonus(char *string, char c);

//src -> handle_input
void			free_double_arr_on_freeflag(char **str, int err_flag);
char			*copy_token(const char *token_start, int token_len);
size_t			count_words(const char *str, char delimiter);
const char		*get_token_and_len(const char *str, char c, size_t *len);
char			**tokenize(const char *str, char delimiter);

//src -> stack0_utils
t_node			*ft_last_node(t_node *node);
t_node			*get_min_node(t_node *stack);
t_node			*get_max_node(t_node *stack);
int				get_size(t_node *stack);
int				is_sorted(t_node **stack);

//src -> stack1_init
int				have_same_nbr(t_node *tmp);
int				is_numerics(char *str);
int				build_node(t_node **stack_a, int nb);
int				init_stack_errcheck(t_node **stack_a, char **av, int free_arr);
void			free_stack_on_freeflag(t_node **stack, int free_flag);

//src -> stack2_sort
void			sort_four(t_node **stack_a, t_node **stack_b);
void			sort_three(t_node **stack_a);
void			sort(t_node **stack_a, t_node **stack_b);

//src -> move_init_a
t_node			*get_any_b_smaller_than_a(t_node *a, t_node *b);
void			get_idxinfo(t_node *a, int a_size);
void			get_target_of_a(t_node *stack_a, t_node *stack_b);
void			init_nodes_a(t_node *stack_a, t_node *stack_b);

//src -> move_init_b
t_node			*get_any_a_bigger_than_b(t_node *a, t_node *b);
void			get_target_of_b(t_node *a, t_node *b);
void			init_nodes_b(t_node *stack_a, t_node *stack_b);

//src -> move0_cost
t_node			*set_and_get_cheapest_node(t_node *stack);
void			set_cost_of_a(t_node *a, t_node *b);

//src -> move_move
void			double_rotation(t_node **stack_a, t_node **stack_b);
void			single_rotation(t_node **stack, t_node *top_node, int is_a);
void			a_to_b(t_node **stack_a, t_node **stack_b);
void			b_to_a(t_node **stack_a, t_node **stack_b);
void			min_to_top(t_node **stack);

//operation
void			push(t_node **src, t_node **dest);
void			push_a(t_node **stack_a, t_node **stack_b);
void			push_b(t_node **stack_a, t_node **stack_b);
void			rotate(t_node **stack);
void			rotate_a(t_node **stack_a);
void			rotate_b(t_node **stack_b);
void			rotate_ab(t_node **stack_a, t_node **stack_b);
void			rev_rotate(t_node **stack);
void			rev_rotate_a(t_node **stack_a);
void			rev_rotate_b(t_node **stack_b);
void			rev_rotate_ab(t_node **stack_a, t_node **stack_b);
void			swap(t_node **stack);
void			swap_a(t_node **stack_a);
void			swap_b(t_node **stack_b);
void			swap_ab(t_node **stack_a, t_node **stack_b);

#endif
