/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:29:09 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:26:45 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
convert a upper case to lower case letter if there is one
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
int main(void)
{
	int	c;

	c = 'A';
	printf("%c\n", ft_tolower(c));
	printf("%c\n", tolower(c));
}
*/

/*
gcc ft_tolower.c -Wall -Wextra -Werror
*/
