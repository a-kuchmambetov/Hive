/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 15:54:46 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-28 15:54:46 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);
char			*ft_strncat(char *dest, char *src, unsigned int nb);

unsigned int	ft_strlen(char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	unsigned int	dest_lenght;

	dest_lenght = ft_strlen(dest);
	index = 0;
	while (index < nb && src[index])
	{
		dest[dest_lenght + index] = src[index];
		index++;
	}
	dest[dest_lenght + index] = '\0';
	return (dest);
}
