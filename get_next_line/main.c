/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:43 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/18 11:45:18 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*rec;

	rec = NULL;
	fd = open("file.txt", O_RDONLY);
	//fd = 0;
	while ((rec = get_next_line(fd)))
	{
		printf("%s", rec);
		free(rec);
	}
	return (0);
}
