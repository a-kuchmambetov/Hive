/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 09:25:57 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-22 09:25:57 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	index;
	int	equal;

	index = 0;
	equal = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
		{
			equal = s1[index] - s2[index];
			break ;
		}
		index++;
	}
	return (equal);
}
