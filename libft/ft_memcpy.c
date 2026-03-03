/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:09:43 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:09:44 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;
	size_t				i;

	dest_cpy = dest;
	src_cpy = src;
	i = 0;
	if (!dest && !src)
	{
		return (dest);
	}
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
