/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:34:30 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/10 08:14:16 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char c)
{
	char	*p;

	p = (char *)str;
	while (*p != '\0')
	{
		if ((unsigned char)*p == (unsigned char)c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (NULL);
}
