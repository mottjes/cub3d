/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:32:05 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/26 13:15:34 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void	f(void *first_char)
{
	while (*(char *)first_char)
	{
		*(char *)first_char = 'Z';
		first_char++;
	}
	
}

int	main(void)
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

	ft_lstiter(elem1, f);
	while (elem1)
	{
		printf("%s\n", elem1->content);
		elem1 = elem1->next;
	}
}
*/

/*
gcc ft_lstiter.c -Wall -Wextra -Werror
*/
