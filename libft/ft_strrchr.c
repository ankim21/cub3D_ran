/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:11:11 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:11:12 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)c == *s)
		{
			last = (char *)s;
		}
		s++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last);
}
