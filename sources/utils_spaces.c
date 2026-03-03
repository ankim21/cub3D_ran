/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:03 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:59:04 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (!ft_is_whitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	replace_spaces(t_game *game, char **map_cpy)
{
	int		i;
	int		j;
	char	cur_char;

	i = 0;
	while (game->map.array && game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			cur_char = game->map.array[i][j];
			if (cur_char != '\n' && ft_is_whitespace(cur_char) \
			&& map_cpy[i][j] == 'F')
				game->map.array[i][j] = '1';
			j++;
		}
		i++;
	}
}
