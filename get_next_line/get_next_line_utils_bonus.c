/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:44:38 by qmoreau           #+#    #+#             */
/*   Updated: 2022/01/14 12:19:13 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*my_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	len_s1 = my_strlen(s1);
	len_s2 = my_strlen(s2);
	ret = malloc(sizeof(*ret) * (len_s1 + len_s2 + 1));
	if (ret == NULL)
		return (0);
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		ret[i] = s2[i - len_s1];
		i++;
	}
	ret[i] = '\0';
	if (s1)
		free(s1);
	return (ret);
}

int	my_is_in(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	my_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a && a[i] != 0)
		i++;
	return (i);
}
