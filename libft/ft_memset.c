/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:49:53 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:45 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memset() function writes len bytes of value c (converted to an unsigned char)
to the string b
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = c;
	return (b);
}

/*
int main(void)
{
	char str[25] = "This is a test";
	int c;
	int size;

	c = '/';
	size = 5;
	printf("%s\n", ft_memset(str, c, size));
	printf("%s\n", memset(str, c , size));
}
*/

/*
gcc ft_memset.c -Wall -Wextra -Werror
*/
