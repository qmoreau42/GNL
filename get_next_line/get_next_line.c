/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:03:27 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/17 15:59:08 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*cut_beg(char *save)
{
	int		i;
	char	*ret;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	ret = malloc(i + 2);
	if (!ret)
		return (NULL);
	ret[i + 1] = '\0';
	while (i >= 0)
	{
		ret[i] = save[i];
		i--;
	}
	return (ret);
}

char	*cut_end(char *save)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	i++;
	ret = malloc(my_strlen(save) - i + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (save[i])
	{
		ret[j] = save [i];
		i++;
		j++;
	}
	ret[j] = 0;
	free(save);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save = NULL;
	char		*ret;
	int			lu;

	lu = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (my_is_in(save, '\n') == 0 && lu != 0)
	{
		lu = read(fd, buffer, BUFFER_SIZE);
		if (lu == -1)
			return (NULL);
		buffer[lu] = 0;
		save = my_strjoin(save, buffer);
	}
	free(buffer);
	ret = cut_beg(save);
	save = cut_end(save);
	return (ret);
}
