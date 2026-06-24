/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:03:03 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/17 12:36:24 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FD 1024

char			*get_next_line(int fd);
char			*ft_set_line(char *stash);
char			*ft_fill_buffer(int fd, char *stash, char *buffer);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);

#endif