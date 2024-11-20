#include "includes/libft.h"

/**
 * @note while(*s1), not(s1)
 * @note mv pointer at the end
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*res;
	char	*temp;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	temp = res;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (res);
}