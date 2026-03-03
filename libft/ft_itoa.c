/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:08:58 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 19:08:59 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	find_len_n(long nb)
{
	int	len_nb;

	len_nb = 0;
	if (nb == 0)
	{
		len_nb++;
		return (len_nb);
	}
	if (nb < 0)
	{
		nb = -nb;
		len_nb++;
	}
	while (nb > 0)
	{
		len_nb++;
		nb = nb / 10;
	}
	return (len_nb);
}

static	char	*int_to_string(long nb, int len_nb)
{
	char	*nb_to_string;
	int		i;

	i = len_nb - 1;
	nb_to_string = malloc(sizeof(char) * (len_nb + 1));
	if (!nb_to_string)
		return (NULL);
	nb_to_string[len_nb] = '\0';
	if (nb == 0)
	{
		nb_to_string[0] = '0';
	}
	if (nb < 0)
	{
		nb_to_string[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		nb_to_string[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (nb_to_string);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;

	nb = n;
	str = int_to_string(nb, find_len_n(nb));
	return (str);
}
