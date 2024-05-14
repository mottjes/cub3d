/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:28:21 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:40 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memcpy() copies n bytes src to dst
If dst and src overlap, behavior is undefined
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (cdst == NULL && csrc == NULL)
		return (NULL);
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}

/*
int main(void)
{
	char src1[] = "copy this";
	char dst1[] = ".........";
	int n;

	n = 5;
	printf("%s\n", src1);
	printf("%s\n", dst1);
	ft_memcpy(dst1, src1, n);
	printf("%s\n", dst1);

	char src2[] = "copy this";
	char dst2[] = ".........";

	printf("\n%s\n", src2);
	printf("%s\n", dst2);
	memcpy(dst2, src2, n);
	printf("%s\n", dst2);
}
*/

/*
gcc ft_memcpy.c -Wall -Wextra -Werror
*/
