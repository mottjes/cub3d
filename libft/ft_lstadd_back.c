/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:31:56 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/26 13:14:08 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adds the node ’new’ at the end of the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*last_lst;

	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	last_lst = ft_lstlast(*lst);
	last_lst->next = newnode;
}
