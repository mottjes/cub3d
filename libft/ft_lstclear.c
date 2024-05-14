/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:32:01 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/26 14:39:06 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}

/*
void del(void *lst)
{
	printf("removed: %s\n", (char *)lst);
}

int main(void)
{
	t_list *lst;

	lst = ft_lstnew("word1");
	lst->next = ft_lstnew("word2");
	lst->next->next = ft_lstnew("word3");
	lst->next->next->next = ft_lstnew("word4");
	ft_lstclear(&(lst->next), del);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
*/