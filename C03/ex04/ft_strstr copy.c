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

#include <stdio.h>
#include <string.h>

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
	return ('\0');
}

//int main() {
//    char src[] = "Original string";
//    char to_find[] = " ";

//    char src2[] = "Original string";
//    char to_find2[] = " ";

//    unsigned int size = 2;
//    printf("ft_strstr| %s\n", ft_strstr(src, to_find));
//    printf("strstr | %s\n", strstr(src2, to_find2));

//    return 0;
//}