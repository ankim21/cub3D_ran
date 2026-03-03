/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:33 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 14:07:51 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	get_map_size(t_game *game)
{
	char	*map_line;

	map_line = get_next_line(game->fd);
	while (map_line)
	{
		if (!is_only_space(map_line))
			game->map.max_length++;
		if (map_line)
			free(map_line);
		map_line = get_next_line(game->fd);
	}
	if (!game->map.max_length)
		return (print_error(NO_MAP), FALSE);
	if (game->map.max_length < 3)
		return (print_error(SIZ_MAP), FALSE);
	return (TRUE);
}

bool	get_map_content(t_game *game)
{
	int		i;
	char	*copy;

	i = 0;
	copy = NULL;
	game->map.array = malloc(sizeof(char *) * (game->map.max_length + 1));
	if (!game->map.array)
		return (print_error(FAIL_MAL), FALSE);
	while (i <= game->map.start || is_only_space(copy))
	{
		if (copy)
			free(copy);
		copy = get_next_line(game->fd);
		i++;
	}
	i = 0;
	while (copy)
	{
		game->map.array[i] = copy;
		copy = get_right_copy(game, i, 1);
		i++;
	}
	game->map.array[i] = NULL;
	return (TRUE);
}

static bool	check_validity_map(t_game *game, char *av)
{
	if (!get_map_size(game)) // help understand how this function works
		return (FALSE);
	close(game->fd);
	open_fd(av, game);
	if (!get_map_content(game))
		return (FALSE);
	if (!check_map_content(game))
		return (FALSE);
	return (TRUE);
}

static bool	check_validity_infos(t_game *game)
{
	if (!check_textures_and_colors(game))
		return (FALSE);
	if (!all_infos(game))
		return (print_error(MISSING_INFO), FALSE);
	return (TRUE);
}

int	check_validity_file(char *av, t_game *game)
{
	open_fd(av, game);
	if (!check_validity_infos(game)) 
	{
		close(game->fd);
		return (FALSE);
	}
	if (!check_validity_map(game, av))
	{
		close(game->fd);
		return (FALSE);
	}
	close(game->fd);
	return (TRUE);
}
