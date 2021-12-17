/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:59:22 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/15 17:50:35 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char			*my_realloc(char *ptr, unsigned int newSize);
void			*my_memcpy(void *dest, void *src, unsigned int n);
size_t			my_strlen(const char *a);
int				my_is_in(char *s, char c);
char			*my_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);

#endif
