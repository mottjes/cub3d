/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:09:52 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:26:29 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*
char	f(unsigned int i, char str)
{
	i = 0 ;
	return (str - 32);
}

int main(void)
{
	char str[] = "helloworld";
	printf("%s\n", ft_strmapi(str, f));
}
*/

/*
gcc ft_strmapi.c ft_strlen.c -Wall -Wextra -Werror
*/
