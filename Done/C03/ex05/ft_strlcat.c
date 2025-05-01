/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 13:56:09 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-23 13:56:09 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_lenght;

	dest_lenght = ft_strlen(dest);
	index = 0;
	while (index < size - 1 && src[index])
	{
		dest[dest_lenght + index] = src[index];
		index++;
	}
	dest[dest_lenght + index] = '\0';
	return (dest_lenght + ft_strlen(src));
}
