/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:03:27 by qmoreau           #+#    #+#             */
/*   Updated: 2022/01/21 15:55:58 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*cut_beg(char *save)
{
	int		i;
	char	*ret;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		ret = malloc(i + 2);
	else
		ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	if (save[i] == '\n')
		ret[i + 1] = '\0';
	while (i >= 0)
	{
		ret[i] = save[i];
		i--;
	}
	return (ret);
}

int	cut_end_2(char *save, char *ret, int i)
{
	int	j;

	j = 0;
	while (save[i])
	{
		ret[j] = save[i];
		i++;
		j++;
	}
	return (j);
}

char	*cut_end(char *save, int lu)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (!save[0] || lu == 0)
	{
		free(save);
		return (NULL);
	}
	while (save[i] != '\n' && save[i])
		i++;
	i++;
	ret = malloc(my_strlen(save) - i + 1);
	if (!ret)
		return (NULL);
	j = cut_end_2(save, ret, i);
	ret[j] = 0;
	free(save);
	return (ret);
}

char	*get_next_line_2(int fd)
{
	char	*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = malloc(BUFFER_SIZE + 1);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save[OPEN_MAX];
	char		*ret;
	int			lu;

	lu = 1;
	buffer = get_next_line_2(fd);
	if (!buffer)
		return (NULL);
	while (lu > 0 && my_is_in(save[fd], '\n') == 0)
	{
		lu = read(fd, buffer, BUFFER_SIZE);
		if (lu == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[lu] = 0;
		save[fd] = my_strjoin(save[fd], buffer);
	}
	free(buffer);
	ret = cut_beg(save[fd]);
	save[fd] = cut_end(save[fd], lu);
	return (ret);
}
