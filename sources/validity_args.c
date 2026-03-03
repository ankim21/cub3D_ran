/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:12 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 13:37:53 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_file_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'b')
		return (FALSE);
	if (str[i - 1] != 'u')
		return (FALSE);
	if (str[i - 2] != 'c')
		return (FALSE);
	if (str[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}

int	check_validity_args(int ac, char *av)
{
	if (ac != 2)
		return (print_error(NB_ARGS), FALSE); // check for error
	if (!check_file_name(av))
		return (print_error(EXT), FALSE); // check for extension 
	return (TRUE);
}
