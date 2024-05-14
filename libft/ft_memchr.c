/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:47:00 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:34 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memchr() function locates the first occurrence 
of c (converted to an unsigned char) in string s
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	character;

	character = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n)
	{
		if (*ptr == character)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/*
int main(void)
{
	char str[] = "Hello World";
	int c;
	size_t n;

	c = 0;
	n = 0;
	printf("%s\n", ft_memchr(str, c, n));
	printf("%s\n", memchr(str, c, n));
}
*/

/*
gcc ft_memchr.c -Wall -Wextra -Werror
*/