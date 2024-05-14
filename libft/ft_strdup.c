/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:22:21 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:25:47 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strdup() function allocates sufficient memory for a copy of the string s1, 
does the copy, and returns a pointer to it.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*
int main(void)
{
	char str[] = "Hello";

	printf("%s\n", ft_strdup(str));
	printf("%s\n", strdup(str));
}
*/

/*
gcc ft_strdup.c ft_strlen.c -Wall -Wextra -Werror
*/
