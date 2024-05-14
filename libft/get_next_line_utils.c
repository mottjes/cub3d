/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:06:32 by mottjes           #+#    #+#             */
/*   Updated: 2024/01/30 12:13:33 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*append_buffer(char *save, char *buff)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	if (!buff)
		return (free(save), NULL);
	new_save = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buff) + 1));
	if (!new_save)
		return (free(save), NULL);
	while (save[i])
	{
		new_save[i] = save[i];
		i++;
	}
	while (buff[j])
		new_save[i++] = buff[j++];
	new_save[i] = '\0';
	free(save);
	return (new_save);
}
