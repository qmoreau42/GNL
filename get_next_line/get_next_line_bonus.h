/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:59:22 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/19 18:07:57 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

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
