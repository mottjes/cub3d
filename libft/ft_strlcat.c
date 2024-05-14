/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:42:35 by mottjes           #+#    #+#             */
/*   Updated: 2024/02/06 14:02:35 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
size-bounded string concatenation
take the full size of the destination buffer and guarantee NUL-termi-
nation if there is room
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (!dstsize)
		return (srclen);
	while ((dstlen + i) < (dstsize - 1) && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	if (dstlen > dstsize)
		return (srclen + dstsize);
	return (srclen + dstlen);
}

/*
int main(void)
{
	char dest[50] = "Hello";
	char src[] = "World";
	size_t size;
	
	size = 10;
	printf("%s\n", dest);
	printf("%lu\n", ft_strlcat(dest, src, size));
	printf("%s\n", dest);

	char dest2[50] = "Hello";
	char src2[] = "World";
	
	printf("%s\n", dest2);
	printf("%lu\n", strlcat(dest2, src2, size));
	printf("%s\n", dest2);
}
*/

/*
gcc ft_strlcat.c ft_strlen.c -Wall -Wextra -Werror
*/
