/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nal-haki <nal-haki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:21:04 by nal-haki          #+#    #+#             */
/*   Updated: 2024/07/30 10:21:22 by nal-haki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*tmp_new;
	t_list		*tmp_lst;

	new = ft_lstnew((*f)(lst->content));
	if (!lst || !new)
		return (NULL);
	tmp_new = new;
	tmp_lst = lst->next;
	while (tmp_lst)
	{
		tmp_new->next = ft_lstnew((*f)(tmp_lst->content));
		if (!tmp_new->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmp_new = tmp_new->next;
		tmp_lst = tmp_lst->next;
	}
	return (new);
}
