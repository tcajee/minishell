/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <mbaloyi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/17 18:00:31 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static int	find_quote(const char *str, int i)
{
	char *pos;

	i++;
	while ((pos = ft_strchr(str + i, '\"')))
		if (str[i - 1] != '\\')
			break ;
	if (!pos)
		return (0);
	return (pos - str);
}

static int	count_words(char const *str)
{
	int		i;
	int		last_was_split;
	int		count;

	last_was_split = 1;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			last_was_split = 1;
		else
		{
			if (last_was_split)
				count++;
			if (last_was_split && str[i] == '\"')
				if (!(i = find_quote(str, i)))
					return (0);
			last_was_split = 0;
		}
		i++;
	}
	return (count);
}

static void	fill_array(char **result, char const *str)
{
	int		current_word;
	int		i;
	char	*start;

	i = -1;
	current_word = 0;
	while (str[++i])
		if (str[i] == '\"')
		{
			start = (char *)str + i++ + 1;
			while (str[i] && (str[i] != '\"' || str[i - 1] == '\''))
				i++;
			result[current_word] = *ft_strsplit(start, str + i-- - start);
			current_word++;
		}
		else if ((str[i]) != ' ')
		{
			start = (char *)str + i;
			while ((str[i]) != ' '  && str[i])
				i++;
			result[current_word] = ft_strndup(start, str + i-- - start);
			current_word++;
		}
	result[current_word] = 0;
}

char		**ft_strqotsplit(char const *str)
{
	char		**result;
	size_t		words;

	if (!str)
		return (NULL);
	if (!(words = count_words(str)))
		return (NULL);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	fill_array(result, str);
	return (result);
}
