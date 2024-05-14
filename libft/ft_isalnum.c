/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:27 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:09 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if an integer is an alphabetical character or numerical character
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	int	c;

	c = 'A';
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", isalnum(c));
}
*/

/*
gcc ft_isalnum.c -Wall -Wextra -Werror
*/
