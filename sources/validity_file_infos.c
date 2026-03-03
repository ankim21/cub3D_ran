/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_file_infos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:25 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 14:06:26 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	all_infos(t_game *game)
{
	if (game->assets.east && game->assets.north \
		&& game->assets.south && game->assets.west \
		&& game->assets.ceiling_flag == 1 && game->assets.floor_flag == 1)
		return (TRUE);
	return (FALSE);
}

static bool	check_double_infos(char *s, t_game *game)
{
	if (!ft_strcmp(s, "NO") && game->assets.north)
		return (TRUE);
	if (!ft_strcmp(s, "SO") && game->assets.south)
		return (TRUE);
	if (!ft_strcmp(s, "WE") && game->assets.west)
		return (TRUE);
	if (!ft_strcmp(s, "EA") && game->assets.east)
		return (TRUE);
	if (!ft_strcmp(s, "C") && game->assets.ceiling_flag)
		return (TRUE);
	if (!ft_strcmp(s, "F") && game->assets.floor_flag)
		return (TRUE);
	return (FALSE);
}

static bool	check_textures_and_colors_validity(char **split_copy, t_game *game)
{
	// understood if on the first char* is not a color line and we are not on texture line, we 
	// are printing error
	// params must be defined first
	// doubts about on_texture_line
	if (!on_color_line(split_copy[0]) && !on_texture_line(split_copy[0]))
		return (print_error(INV_PARAM), FALSE);
	if (check_double_infos(split_copy[0], game)) // but when do we init game that is not /\0??
		return (print_error(DOUBLE), FALSE);
	if (on_texture_line(split_copy[0]) \
		&& !check_textures_line(split_copy, game))
		return (FALSE);
	else if (on_color_line(split_copy[0]) \
		&& !check_color_line(split_copy, game))
		return (FALSE);
	return (TRUE);
}

bool	check_textures_and_colors(t_game *game)
{
	char	*copy;
	char	**split_copy;
	int		i;

	i = 0;
	while (i < 6)
	{
		copy = get_right_copy(game, -1, 0); // did you mean not  0 but i ?
		split_copy = ft_split(copy); // char** split_copy
		if (split_copy && split_copy[0])
		{
			if (!check_textures_and_colors_validity(split_copy, game))
				return (free(copy), free_2d_array(split_copy), FALSE);
		}
		free(copy);
		free_2d_array(split_copy);
		game->map.start++;
		i++;
	}
	if (!all_infos(game))
		return (print_error(MISSING_INFO), FALSE);
	return (TRUE);
}

// suggestion for parsing the texture and colors :
