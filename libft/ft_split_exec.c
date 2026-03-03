/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:10:11 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:10:12 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	if (c == '\0')
	{
		if (*s == '\0')
			return (0);
		return (1);
	}
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*alloc_word(char *start, int len)
{
	return (ft_substr(start, 0, len));
}

static void	free_tab(char **tabl, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		free(tabl[i]);
		i++;
	}
	free(tabl);
}

static int	fill_tab(char **tabl, char *s, char c)
{
	int		i;
	char	*start;
	char	*end;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		end = (char *)s;
		tabl[i] = alloc_word(start, end - start);
		if (tabl[i] == NULL)
		{
			free_tab(tabl, i);
			return (1);
		}
		i++;
	}
	tabl[i] = NULL;
	return (0);
}

char	**ft_split_exec(char *s, char c)
{
	int		words;
	char	**tabl;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tabl = malloc((words + 1) * sizeof(char *));
	if (!tabl)
		return (NULL);
	if (fill_tab(tabl, s, c))
		return (free(tabl), NULL);
	return (tabl);
}
