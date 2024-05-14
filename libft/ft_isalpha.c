/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:39:01 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:14 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if an integer is an alphabetical character 
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	int c;

	c = 'A';
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(c));
}
*/

/*
gcc ft_isalpha.c -Wall -Wextra -Werror
*/
