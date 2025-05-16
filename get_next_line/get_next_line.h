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
char	*ft_append_str(char *original, const char *addition);

#endif