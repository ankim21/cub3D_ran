/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_map_infos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:37 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:59:38 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_for_target(t_point *start, char **map, int max_width)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j] && j < max_width -1)
		{
			if (map[i][j] == '0' || is_valid_player_char(map[i][j]))
			{
				start->x = j;
				start->y = i;
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

bool	flood_fill_algorithm(char **map, t_point size, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '\0' || map[y][x] == '\n')
		return (FALSE);
	else if (x < 0 || x >= size.x -1 || y < 0 \
		|| y >= size.y -1 || map[y][x] == 'F' || map[y][x] == '1')
		return (TRUE);
	else
	{
		map[y][x] = 'F';
		if (!flood_fill_algorithm(map, size, x, y + 1))
			return (FALSE);
		if (!flood_fill_algorithm(map, size, x, y - 1))
			return (FALSE);
		if (!flood_fill_algorithm(map, size, x + 1, y))
			return (FALSE);
		if (!flood_fill_algorithm(map, size, x - 1, y))
			return (FALSE);
	}
	return (TRUE);
}

static void	get_max_size(t_game *game)
{
	int	i;
	int	cur_width;

	i = 0;
	cur_width = 0;
	while (game->map.array && game->map.array[i])
	{
		cur_width = ft_strlen(game->map.array[i]);
		if (cur_width > game->map.max_width)
			game->map.max_width = cur_width;
		i++;
	}
	game->map.max_length = i;
}

bool	check_top_and_bottom(char *top, char *bottom)
{
	int	i;

	i = 0;
	while (top && top[i])
	{
		if (top[i] != '1' && !ft_is_whitespace(top[i]))
			return (FALSE);
		i++;
	}
	i = 0;
	while (bottom && bottom[i])
	{
		if (bottom[i] != '1' && !ft_is_whitespace(bottom[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	**get_map_copy(t_game *game)
{
	char	**cpy;
	int		i;

	get_max_size(game);
	cpy = malloc((game->map.max_length + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	cpy[game->map.max_length] = NULL;
	i = 0;
	while (game->map.array && game->map.array[i])
	{
		cpy[i] = malloc((game->map.max_width + 1) * sizeof(char));
		if (!cpy[i])
			return (dump(cpy, i), NULL);
		ft_bzero(cpy[i], game->map.max_width + 1);
		ft_strlcpy(cpy[i], game->map.array[i], game->map.max_width + 1);
		i++;
	}
	return (cpy);
}
