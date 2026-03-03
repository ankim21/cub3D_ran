/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_file_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:29 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 15:53:24 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_player_char(char c)
{
	if (c == 'W' || c == 'E' || c == 'S' || c == 'N')
		return (TRUE);
	return (FALSE);
}

static bool	check_borders(t_game *game)
{
	t_point	start;
	t_point	size;
	char	**map_cpy;

	if (!check_top_and_bottom(game->map.array[0], \
		game->map.array[game->map.max_length - 1]))
		return (FALSE);
	map_cpy = get_map_copy(game);
	if (!map_cpy)
		return (FALSE);
	size.x = game->map.max_width;
	size.y = game->map.max_length;
	while (check_for_target(&start, map_cpy, game->map.max_width))
	{
		if (!flood_fill_algorithm(map_cpy, size, start.x, start.y))
			return (free_2d_array(map_cpy), FALSE);
	}
	replace_spaces(game, map_cpy);
	free_2d_array(map_cpy);
	return (TRUE);
}

static bool	check_invalid_char(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != 'C' && line[i] != 'F' && line[i] != '0'
			&& line[i] != '1' && !is_valid_player_char(line[i])
			&& !ft_is_whitespace(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static bool	check_player_amount(t_game *game, char *line, int pos_y)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == 'E' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W')
		{
			game->ray.pos_x = i + 0.5; // why do we change ray positions?
			game->ray.pos_y = pos_y + 0.5;
			game->player.orientation = line[i];
			game->player.is_player++;
		}
		i++;
	}
	return (TRUE); // VOID RETURN?
}

bool	check_map_content(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.array && game->map.array[i])
	{
		if (!check_invalid_char(game->map.array[i]))
			return (print_error(GARB), FALSE);
		check_player_amount(game, game->map.array[i], i);
		i++;
	}
	if (game->player.is_player != 1)
		return (print_error(PLAYER), FALSE);
	if (!check_borders(game))
		return (print_error(MISS_WALLS), FALSE);
	return (TRUE);
}
