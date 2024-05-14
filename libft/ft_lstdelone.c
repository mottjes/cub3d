/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:32:03 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/26 14:41:22 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free (lst);
}

/*
void del(void *lst)
{
	while (*(char *)lst)
	{
		*(char *)lst = 0;
		lst++;
	}
}

int main(void)
{
	
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	char *w1;
	char *w2;
	char *w3;

	if(!(elem1 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem2 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem3 = malloc(sizeof(t_list))))
		return (0);

	w1 = malloc(sizeof(char) * 6);
	ft_strlcpy(w1, "word1", 6);
	w2 = malloc(sizeof(char) * 6);
	ft_strlcpy(w2, "word2", 6);
	w3 = malloc(sizeof(char) * 6);
	ft_strlcpy(w3, "word3", 6);
	
	elem1->next = elem2;
	elem1->content = w1;
	elem2->next = elem3;
	elem2->content = w2;
	elem3->next = NULL;
	elem3->content = w3;

	ft_lstdelone(elem2, del);
	while (elem1)
	{
		printf("%s\n", elem1->content);
		elem1 = elem1->next;
	}
}
*/