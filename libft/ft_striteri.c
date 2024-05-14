/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:36:32 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:25:49 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	f(unsigned int i, char *str)
{
	i = 0;
	*str -= 32;
}

int main(void)
{
	char str[] = "helloworld";

	ft_striteri(str, f);
	printf("%s\n", str);
}
*/

/*
gcc ft_striteri.c ft_strlen.c -Wall -Wextra -Werror
*/
