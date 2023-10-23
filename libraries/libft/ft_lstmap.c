/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:44:53 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/05 10:44:48 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	temp = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		new = ft_lstnew(ptr);
		if (!new)
		{
			ft_lstclear(&temp, del);
			del(ptr);
			return (NULL);
		}
		ft_lstadd_back(&temp, new);
		lst = lst->next;
	}
	return (temp);
}
