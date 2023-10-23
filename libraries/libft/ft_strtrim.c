/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:43:45 by victgonz          #+#    #+#             */
/*   Updated: 2023/05/11 08:57:25 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_instr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_instr((char *)set, s1[start]))
		start++;
	return (start);
}

static int	end(const char *s1, const char *set)
{
	size_t	len;

	len = ft_strlen((char *)s1);
	while (0 < len && ft_instr((char *)set, s1[len - 1]))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		s;
	int		e;

	if (s1)
	{
		s = start(s1, set);
		e = end(s1, set);
		if (s >= e)
			return (ft_strdup(""));
		str = malloc(sizeof(char) * (e - s + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, (char *)s1 + s, e - s + 1);
		return (str);
	}
	return (NULL);
}
