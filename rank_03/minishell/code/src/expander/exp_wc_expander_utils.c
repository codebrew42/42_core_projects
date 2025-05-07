/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_wc_expander_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:08:31 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/03 16:48:03 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"

int				filter_line(char *s, char *fil);
static void		init_match_state(t_match_state *state);
void			sort_args(char ***args);
void			swap_str(char **s1, char **s2);

int	filter_line(char *s, char *fil)
{
	t_match_state	st;

	init_match_state(&st);
	if (s[0] == '.' && fil[0] != '.')
		return (0);
	while (s[st.string_ptr] != '\0')
	{
		if (fil[st.pattern_ptr] == '*')
		{
			st.last_star_pos = st.pattern_ptr++;
			st.string_pos_after_star = st.string_ptr;
		}
		else if (fil[st.pattern_ptr] == s[st.string_ptr] && ++st.string_ptr)
			st.pattern_ptr++;
		else if (st.last_star_pos != -1)
		{
			st.pattern_ptr = st.last_star_pos + 1;
			st.string_ptr = ++st.string_pos_after_star;
		}
		else
			return (0);
	}
	while (fil[st.pattern_ptr] == '*')
		st.pattern_ptr++;
	return (fil[st.pattern_ptr] == '\0' && s[st.string_ptr] == '\0');
}

static void	init_match_state(t_match_state *state)
{
	state->string_ptr = 0;
	state->pattern_ptr = 0;
	state->last_star_pos = -1;
	state->string_pos_after_star = 0;
}

void	sort_args(char ***args)
{
	char	**tmp;
	char	**av;
	int		i;

	if (!args || !*args)
		return ;
	av = *args;
	if (!*av || !(av[1]))
		return ;
	i = -1;
	while (av[++i])
	{
		tmp = av;
		while (*(tmp + 1))
		{
			if (!ft_issorted(*tmp, *(tmp + 1)))
				swap_str(tmp, tmp + 1);
			tmp++;
		}
	}
}

void	swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_issorted(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (!*s1 && *s2)
		return (1);
	else if (*s1 && !*s2)
		return (0);
	if (*s1 < *s2)
		return (1);
	return (0);
}
/*
int	ft_issorted(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (!*s1 && *s2)
		return (1);
	else if (*s1 && !*s2)
		return (0);
	else if (ft_isdigit(*s1) && !ft_isdigit(*s2))
		return (1);
	else if (ft_isdigit(*s2))
		return (0);
	else if (!ft_isalpha(*s1) && ft_isalpha(*s2))
		return (1);
	else if (!ft_isalpha(*s2))
		return (0);
	if (ft_tolower(*s1) < ft_tolower(*s2))
		return (1);
	return (0);
}
*/
