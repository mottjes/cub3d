/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:05:48 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:43 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
the memmove() function copies len bytes from string src to string dst
The two strings may overlap
the copy is always done in a non-destructive manner.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (len--)
			cdst[len] = csrc[len];
	else
		while (len--)
			*cdst++ = *csrc++;
	return (dst);
}

/*
int	main(void)
{
	int src[10] = {1 ,2 ,3 , 4, 5, 6, 7, 8, 9, 10};
	int src2[10] = {1 ,2 ,3 , 4, 5, 6, 7, 8, 9, 10};
	int i = 0;

	ft_memmove(src +2, src, sizeof(int) * 8);
	printf("<-----ft_memmove------->\n");
	while (i < 10)
	{
		printf("src[%d]=%d\n", i, src[i]);
		i++;
	}
	
	i = 0;
	memmove(src2+2, src2, sizeof(int) * 8);
	printf("<--------memmove------->\n");
	while (i < 10)
	{
		printf("src2[%d]=%d\n", i, src2[i]);
		i++;
	}
}
*/

/*
gcc ft_memmove.c -Wall -Wextra -Werror
*/
