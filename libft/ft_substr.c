/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:11:18 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:11:19 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;
	size_t	i;

	if (!s || start >= ft_strlen(s))
	{
		s_copy = malloc(sizeof(char) * 1);
		if (!s_copy)
			return (NULL);
		s_copy[0] = '\0';
		return (s_copy);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	s_copy = malloc(sizeof(char) * (len + 1));
	if (!s_copy)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		s_copy[i] = s[start + i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
