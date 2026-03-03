/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:11:04 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:11:06 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, int n)
{
	char	*extract;
	int		i;

	i = 0;
	extract = malloc(n + 1);
	if (!extract)
		return (NULL);
	while (s[i] && i < n)
	{
		extract[i] = s[i];
		i++;
	}
	extract[i] = '\0';
	return (extract);
}
