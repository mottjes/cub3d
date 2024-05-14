/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:33:03 by mottjes           #+#    #+#             */
/*   Updated: 2024/02/06 14:01:49 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The calloc() function contiguously allocates enough space for count objects 
that are size bytes of memory each and returns 
a pointer to the allocated memory 
The allocated memory is filled with bytes of value zero.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*
int main(void)
{
	printf("%s\n", ft_calloc(10, sizeof(int)));
	printf("%s\n", calloc(10, sizeof(int)));
}
*/

/*
gcc ft_calloc.c -Wall -Wextra -Werror
*/
