/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_ev_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:22:35 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/04 19:33:24 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"

char		*ev_expander(t_mshell *data, char *line);
static void	create_exp_lst(t_mshell *data, t_list **lst, char *line);
static void	parse_line(t_mshell *data, t_list *lst, char *line, char *top);
static char	*get_substr_env(t_mshell *data, char *top, char *next);
static char	*get_env_var(t_env *env, char *line, char *end, int excode);

char	*ev_expander(t_mshell *data, char *line)
{
	t_list	*lst;
	char	*new;

	if (!line || !*line)
		return (line);
	if (!ft_strchr(line, '$'))
		return (line);
	if (!ft_strcmp(line, "$"))
		return (line);
	create_exp_lst(data, &lst, line);
	new = create_new_line(lst);
	ft_lstclear(&lst, &free);
	free(line);
	return (new);
}

static void	create_exp_lst(t_mshell *data, t_list **lst, char *line)
{
	*lst = ft_lstnew(NULL);
	if (!lst)
		err_exit(NULL, 0);
	parse_line(data, *lst, line, line);
}

static void	parse_line(t_mshell *data, t_list *lst, char *line, char *top)
{
	char	*next;
	char	*sub;

	if (!top || !lst)
		return ;
	next = set_next_p(top);
	sub = 0;
	sub = get_substr_env(data, top, next);
	if (!sub)
		errno_exit(data);
	lst->content = (void *)sub;
	if (!*next)
		lst->next = NULL;
	else
	{
		lst->next = ft_lstnew((void *)sub);
		if (!lst->next)
			errno_exit(data);
		parse_line(data, lst->next, line, next);
	}
}

static char	*get_substr_env(t_mshell *data, char *top, char *next)
{
	if (next && *top == '$')
	{
		if (next == top + 1)
			return (ft_strdup("$"));
		else
			return (get_env_var(data->env_var, top, next - 1, \
			data->dol_questn));
	}
	else if (next && *next == '$')
		return (ft_substr(top, 0, next - top));
	else
		return (ft_strdup(top));
}

static char	*get_env_var(t_env *env, char *line, char *end, int excode)
{
	char	*key;
	char	*envval;
	char	*value;

	envval = NULL;
	value = NULL;
	line++;
	key = ft_substr(line, 0, end - line + 1);
	if (!key)
		return (NULL);
	if (check_dol_questn(key, &envval, excode))
		return (free(key), NULL);
	if (envval)
		return (free(key), envval);
	if (digit_key(key, &envval))
		return (free(key), NULL);
	if (envval)
		return (free(key), envval);
	value = get_env_val(env, key);
	if (value)
		return (free(key), ft_strdup(value));
	if (!envval)
		envval = ft_strdup("");
	return (free(key), envval);
}
