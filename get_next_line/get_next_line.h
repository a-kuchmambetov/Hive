/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 12:21:59 by akuchmam          #+#    #+#             */
/*   Updated: 2025-05-14 12:21:59 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdlib.h"
# include "unistd.h"

#define BUFFER_SIZE 42;

char	*get_next_line(int fd);
// Utils
int		ft_get_newline_i(char *src);
char	*ft_append_str(const char *original, const char *addition);

#endif