/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwong <cwong@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:05:27 by cwong             #+#    #+#             */
/*   Updated: 2025/02/02 18:05:35 by cwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free_entries(t_dict_entry *entries, int size)
{
	int	i;

	i = 0;
	if (!entries)
		return ;
	while (i < size)
	{
		free(entries[i].key);
		free(entries[i].value);
		i++;
	}
	free(entries);
}

char	*ft_trim_spaces(char *str)
{
	char	*end;

	while (*str && ft_isspace(*str))
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}

t_dict_entry	*ft_realloc_entries(t_dict_entry **entries, int *size)
{
	t_dict_entry	*new_entries;
	int				i;

	new_entries = malloc((*size + 1) * sizeof(t_dict_entry));
	if (!new_entries)
	{
		ft_free_entries(*entries, *size);
		ft_free_entries(new_entries, *size);
		return (NULL);
	}
	i = 0;
	while (i < *size)
	{
		new_entries[i].key = (*entries)[i].key;
		new_entries[i].value = (*entries)[i].value;
		i++;
	}
	free(*entries);
	return (new_entries);
}

int	ft_dict_error(t_dict_entry **entries, t_dict_entry *new_entries, int *size)
{
	ft_free_entries(new_entries, *size);
	ft_free_entries(*entries, *size);
	write(1, "Dict Error\n", 11);
	return (-1);
}

int	ft_process_entry(char *ptr, int *size, t_dict_entry **entries)
{
	char			*colon;
	char			*number;
	char			*value;
	t_dict_entry	*new_entries;

	new_entries = NULL;
	colon = ft_strchr(ptr, ':');
	if (!colon)
		return (ft_dict_error(entries, new_entries, size));
	*colon = '\0';
	number = ft_trim_spaces(ptr);
	value = ft_trim_spaces(colon + 1);
	if (*number == '\0' || *value == '\0')
		return (ft_dict_error(entries, new_entries, size));
	new_entries = ft_realloc_entries(entries, size);
	if (!new_entries)
		return (-1);
	new_entries[*size].key = ft_strdup(number);
	new_entries[*size].value = ft_strdup(value);
	*entries = malloc((*size + 1) * sizeof(t_dict_entry));
	if (!(*entries))
		return (ft_dict_error(entries, new_entries, size));
	*entries = new_entries;
	(*size)++;
	return (0);
}
