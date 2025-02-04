/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 11:56:24 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-22 11:56:24 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_lenght;

	dest_lenght = ft_strlen(dest);
	index = 0;
	while (src[index])
	{
		dest[dest_lenght + index] = src[index];
		index++;
	}
	dest[dest_lenght + index] = '\0';
	return (dest);
}
