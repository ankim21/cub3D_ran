/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:10:14 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:10:16 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words_count(char *s)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i] && ft_is_whitespace(s[i]))
		i++;
	if (!s[i])
		return (count_words);
	while (s[i])
	{
		while (s[i] && ft_is_whitespace(s[i]))
			i++;
		if (s[i] != '\0')
			count_words++;
		while (s[i] && !ft_is_whitespace(s[i]))
			i++;
	}
	return (count_words);
}

static int	how_many_letters(char *s, int start)
{
	int	len;

	len = 0;
	while (s[start] && ft_is_whitespace(s[start]))
		start++;
	while (s[start] && !ft_is_whitespace(s[start]))
	{
		start++;
		len++;
	}
	return (len);
}

static void	free_all(char **tab, int words)
{
	while (words != 0)
	{
		words--;
		free(tab[words]);
	}
	free(tab);
}

static char	**fill_tab(char *s, char **tab, int words)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	while (words > 0)
	{
		while (s[i] && ft_is_whitespace(s[i]))
			i++;
		tab[n] = malloc(sizeof(char) * (how_many_letters(s, i) + 1));
		if (!tab[n])
			return (free_all(tab, n), NULL);
		j = 0;
		while (s[i] && !ft_is_whitespace(s[i]))
			tab[n][j++] = s[i++];
		tab[n][j] = '\0';
		n++;
		words--;
	}
	return (tab);
}

char	**ft_split(char *s)
{
	int		num_words;
	char	**tab;

	if (!s)
		return (NULL);
	num_words = ft_words_count(s);
	tab = malloc(sizeof(char *) * (num_words + 1));
	if (!tab)
		return (NULL);
	tab[num_words] = NULL;
	tab = fill_tab(s, tab, num_words);
	return (tab);
}
