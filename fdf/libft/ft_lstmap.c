/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:14:07 by ohortal-          #+#    #+#             */
/*   Updated: 2023/02/14 12:28:09 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*new_tlist(t_list **new_list, t_list **tmp, void **content)
{
	if (*tmp)
	{
		(*tmp)-> next = ft_lstnew(*content);
		if (!(*tmp)-> next)
			return (NULL);
		*tmp = (*tmp)-> next;
	}
	else
	{
		*tmp = ft_lstnew(*content);
		if (!*tmp)
			return (NULL);
		*new_list = *tmp;
	}
	return (*tmp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_list;
	void	*content;

	new_list = NULL;
	tmp = new_list;
	while (lst && f && del)
	{
		content = f(lst -> content);
		if (!content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_tlist(&new_list, &tmp, &content))
		{
			if (tmp && !tmp -> next)
				ft_lstclear(&new_list, del);
			free(content);
			return (NULL);
		}
		lst = lst -> next;
	}
	return (new_list);
}
