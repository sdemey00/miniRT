/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:44:21 by mmichele          #+#    #+#             */
/*   Updated: 2025/04/18 21:38:19 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*check_error(t_list **root, t_list *cur_c, void (*del)(void *))
{
	if (cur_c)
		del(cur_c);
	ft_lstclear(root, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	const t_list	*lst_ref = lst;
	t_list			*root;
	t_list			*cur_l;
	void			*cur_c;

	if (!f || !del)
		return (0);
	root = 0;
	while (lst)
	{
		cur_c = f(lst->content);
		cur_l = ft_lstnew(cur_c);
		if (!cur_l)
			check_error(&root, cur_c, del);
		if (lst == lst_ref)
			root = cur_l;
		else
			ft_lstadd_back(&root, cur_l);
		lst = lst->next;
	}
	return (root);
}
