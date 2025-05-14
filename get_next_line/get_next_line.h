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

typedef struct read_data {
	char	*string;
	int		end_of_line;
	
}	t_read_data;

char	*get_next_line(int fd);

#endif