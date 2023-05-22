/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:41:55 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/10 08:14:16 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		x;

	if (s1 && s2)
	{	
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
		str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (!str)
			return (0);
		x = -1;
		while (s1[++x])
			str[x] = s1[x];
		x = -1;
		while (s2[++x])
			str[x + len_s1] = s2[x];
		str[x + len_s1] = '\0';
		return (str);
	}
	return (NULL);
}
