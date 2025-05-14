/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 19:10:52 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-02 19:10:52 by akuchmam         ###   ########akuchmam  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_getval_dict_key(char *key,
t_dict_entry *dict, int dict_size)
{
	int		index;

	index = 0;
	while (index < dict_size)
	{
		if (ft_str_equal(key, dict[index].key))
			return (dict[index].value);
		index++;
	}
	return (0);
}

char	*ft_getvalue_dict_skey(char singlekey,
t_dict_entry *dict, int dict_size)
{
	char	new_key[2];

	new_key[0] = singlekey;
	new_key[1] = '\0';
	return (ft_getval_dict_key(new_key, dict, dict_size));
}
