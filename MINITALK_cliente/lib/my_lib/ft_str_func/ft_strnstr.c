/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:24:19 by victgonz          #+#    #+#             */
/*   Updated: 2023/01/31 14:52:13 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && 0 < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && (j + i) < len)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
