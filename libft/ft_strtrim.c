/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:11:14 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:11:16 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	int		len_s1;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	i = 0;
	j = len_s1 - 1;
	while (is_in_set(s1[i], set) == 1)
		i++;
	while (is_in_set(s1[j], set) == 1)
		j--;
	str_trim = ft_substr(s1, i, j - i + 1);
	if (!str_trim)
		return (NULL);
	return (str_trim);
}
