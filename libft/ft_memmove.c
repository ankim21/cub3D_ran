/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:09:47 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:09:48 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;
	size_t				i;

	dest_cpy = (unsigned char *) dest;
	src_cpy = (unsigned char *) src;
	i = 0;
	if (dest_cpy < src_cpy)
	{
		while (i < n)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	if (dest_cpy > src_cpy)
	{
		while (n--)
		{
			dest_cpy[n] = src_cpy[n];
		}
	}
	return (dest);
}
