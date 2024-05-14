/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:30:19 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:19 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if an integer is an ascii character
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	int	c;

	c = 42;
	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
}
*/

/*
gcc ft_isascii.c -Wall -Wextra -Werror
*/
