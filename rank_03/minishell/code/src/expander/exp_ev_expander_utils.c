/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_expander_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:42:26 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/04/10 18:23:12 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"

int		digit_key(char *key, char **envval);
int		count_linelen(t_list *lst);
char	*set_next_p(char *line);
int		check_dol_questn(char *key, char **envval, int excode);
char	*create_new_line(t_list *lst);

int	digit_key(char *key, char **envval)
{
	if (ft_isdigit(*key))
	{
		if (*key == '0')
			*envval = ft_strdup("minishell");
		else
			*envval = ft_strdup("");
		if (!*envval)
			return (ERR);
	}
	return (0);
}

int	count_linelen(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		n += ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (n);
}

char	*set_next_p(char *line)
{
	char	*p;

	p = line;
	if (*line == '$')
	{
		p++;
		if (!*p || *p == '"' || *p == '\'')
			return (p);
		if (!ft_strncmp(p, "?", 1) || !ft_strncmp(p, "0", 1))
			return (++p);
		else if (ft_isdigit(*p))
			return (++p);
		else
			while (*p && (ft_isalnum(*p) || *p == '_'))
				p++;
	}
	else if (*line != '$')
		p = ft_strchr(line, '$');
	if (!p)
		p = line + ft_strlen(line);
	return (p);
}

int	check_dol_questn(char *key, char **envval, int excode)
{
	if (!ft_strncmp(key, "?", 2))
	{
		*envval = ft_itoa(excode);
		if (!*envval)
			return (ERR);
	}
	return (0);
}

char	*create_new_line(t_list *lst)
{
	int		new_len;
	char	*new;
	char	*tmp;
	char	*sub;

	new_len = count_linelen(lst);
	new = ft_calloc(new_len + 1, 1);
	tmp = new;
	while (lst)
	{
		sub = ((char *)lst->content);
		ft_strlcat(tmp, sub, new_len + 1);
		lst = lst->next;
		tmp += ft_strlen(tmp);
	}
	return (new);
}
