/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 09:12:36 by akuchmam          #+#    #+#             */
/*   Updated: 2025-04-29 09:12:36 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t count_words(const char *str, const char c)
{
	size_t	count; 

	count = 0;
	while (*str)
	{
		if((*str == c && *(str + 1) != c)|| *(str + 1) == '\0')
			count++;
		str++;
	}
	return (count);
}

static char	*add_word(const char *src, size_t len)
{
	char	*str;

	str = ft_calloc(1, len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, len+1);
	return (str);
}

static char	*trim(char const *s, char c)
{
	const char	sep[2] = {c, '\0'};
	const char	*p = sep;

	return (ft_strtrim(s,p));
}

char	**ft_split(char const *s, char c)
{
	const char		*trimed = trim(s,c);
	const size_t	words_num = count_words(trimed, c);
	size_t			word_len;
	size_t			index;
	char			**str;

	str = malloc((words_num + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[words_num] = '\0';
	index = 0;
	while (words_num - index > 0)
	{
		word_len = 0;
		while (trimed[word_len] != c)
			word_len++;
		str[index] = add_word(trimed, word_len);
		while(trimed[word_len] == c)
			word_len++;
		trimed = &trimed[word_len];
		index++;
	}
	return (str);
}

//#include "stdio.h"

int main() {
    char * s1 = "    Test        second    one   ";
    // Write C code here
    char **str = ft_split(s1,' ');

    return 0;
}