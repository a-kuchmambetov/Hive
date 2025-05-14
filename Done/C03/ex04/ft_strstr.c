/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 10:09:42 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-23 10:09:42 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	iterator;
	int	in_iterator;

	if (*to_find == '\0')
		return (str);
	iterator = 0;
	while (str[iterator])
	{
		if (str[iterator] == to_find[0])
		{
			in_iterator = 0;
			while (str[iterator] == to_find[in_iterator])
			{
				if (to_find[in_iterator + 1] == 0)
					return (&str[iterator - in_iterator]);
				iterator++;
				in_iterator++;
			}
			iterator -= in_iterator;
		}
		iterator++;
	}
	return ((void *)0);
}
