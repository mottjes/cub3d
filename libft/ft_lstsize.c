/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:32:14 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/26 08:55:28 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Counts the number of nodes in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst == NULL)
		return (size);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
int	main(void)
{

}
*/

/*

*/
