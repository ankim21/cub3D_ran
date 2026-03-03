/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:10:36 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:10:37 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!s_join)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len_s1)
	{
		s_join[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		s_join[i++] = s2[j++];
	s_join[i] = '\0';
	return (s_join);
}
