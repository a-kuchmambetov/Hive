/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:11:24 by timurray          #+#    #+#             */
/*   Updated: 2025/02/02 17:05:04 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ceiling(int num, int divisor);
char	*process_input(char *str);
int		strlen_num(char *str);
void	write_error(void);
char	*validate_input(char *str);

char	**convert_num(char *nb)
{
	int		length;
	int		i;
	int		index;
	char	**num_str;

	nb = process_input(nb);
	length = strlen_num(nb);
	index = 0;
	num_str = (char **)malloc((ceiling(length, 3) + 1) * sizeof(char *));
	if (!num_str)
		return (NULL);
	while (length > 0)
	{
		num_str[index] = (char *)malloc(4 * sizeof(char));
		if (!num_str[index])
			return (NULL);
		i = 2;
		while (i >= 0 && length > 0)
			num_str[index][i--] = nb[length-- - 1];
		while (i >= 0)
			num_str[index][i--] = '0';
		num_str[index++][3] = '\0';
	}
	num_str[index] = (char *) '\0';
	return (num_str);
}

int	ceiling(int num, int divisor)
{
	if (num % divisor == 0)
		return ((num / divisor));
	else
		return ((num / divisor) + 1);
}

int	strlen_num(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

char	*validate_input(char *str)
{
	int		i;
	char	*start;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		return (NULL);
	else if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (NULL);
	else
	{
		start = &str[i];
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] != '\0')
		return (NULL);
	else
		return (start);
}

char	*process_input(char *str)
{
	char	*nb;
	int		length;
	int		i;

	str = validate_input(str);
	if (str == NULL)
	{
		write_error();
		return (NULL);
	}
	length = strlen_num(str);
	nb = (char *)malloc(length * sizeof(char) + 1);
	if (!nb)
		return (NULL);
	i = 0;
	while (i < length)
		nb[i++] = *str++;
	nb[i] = '\0';
	return (nb);
}
