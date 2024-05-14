/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:06:22 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/25 14:18:48 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
find length of string
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

/*
int	main(void)
{
	char	*a;

	a = "test";
	printf("%lu\n", ft_strlen(a));
	printf("%lu\n", strlen(a));
}
*/

/*
gcc ft_strlen.c -Wall -Wextra -Werror
*/
