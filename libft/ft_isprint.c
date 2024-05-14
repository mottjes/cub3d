/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:52:13 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:29 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if an integer is an printable character
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	int c;

	c = 126;
	printf("%d\n", ft_isprint(c));
	printf("%d\n", isprint(c));
}
*/

/*
gcc ft_isprint.c -Wall -Wextra -Werror
*/
