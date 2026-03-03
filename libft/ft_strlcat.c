/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:10:40 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:10:41 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dst_len;
	size_t	jtmp;

	dst_len = ft_strlen(dst);
	i = 0;
	jtmp = dst_len;
	if ((siz < dst_len && dst_len > 0) || (dst_len == 0 && siz == 0))
	{
		return (siz + ft_strlen(src));
	}
	while (src[i] && dst_len < siz - 1)
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (ft_strlen(src) + jtmp);
}
