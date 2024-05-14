/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:39:49 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:26:23 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
size-bounded string copying
take the full size of the destination buffer and guarantee NUL-termi-
nation if there is room
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while ((dstsize - 1) > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
int main(void)
{
	unsigned int dstsize = 1;
	char src[] = "Hello World";
	char dest[dstsize];
	char dest2[dstsize];

	printf("%lu\n", ft_strlcpy(dest, src, dstsize));
	printf("%s\n", dest);
	printf("%lu\n", strlcpy(dest2, src, dstsize));
	printf("%s\n", dest2);
}
*/

/*
gcc ft_strlcpy.c strlen.c -Wall -Wextra -Werror
*/
