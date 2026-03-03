/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_file_infos_textures.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:21 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 14:03:16 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	on_texture_line(char *s)
{
	if (ft_strcmp(s, "NO") && ft_strcmp(s, "SO") \
		&& ft_strcmp(s, "WE") && ft_strcmp(s, "EA")) // (ft_strcmp(s, "NO") || ft_strcmp(s, "NO")..)
			// return TRUE 
		return (FALSE);
	return (TRUE);
}

static bool	check_valid_path(char **split_copy, char *s, char **game_texture)
{
	if (!split_copy[1])
		return (print_error(NO_PATH), FALSE);
	if (split_copy[2])
		return (print_error(GARB), FALSE);
	if (ft_strcmp(split_copy[1], s))
		return (print_error(W_PATH), FALSE);
	*game_texture = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!game_texture)
		return (print_error(FAIL_MAL), FALSE);
	ft_strcpy(*game_texture, s);
	return (TRUE);
}

bool	check_textures_line(char **split_copy, t_game *game)
{
	if (!ft_strcmp(split_copy[0], "NO") && !game->assets.north)
	{
		if (!check_valid_path(split_copy, \
			split_copy[1], &game->assets.north))
			return (FALSE);
	}
	if (!ft_strcmp(split_copy[0], "SO") && !game->assets.south)
	{
		if (!check_valid_path(split_copy, \
			split_copy[1], &game->assets.south))
			return (FALSE);
	}
	if (!ft_strcmp(split_copy[0], "EA") && !game->assets.east)
	{
		if (!check_valid_path(split_copy, \
			split_copy[1], &game->assets.east))
			return (FALSE);
	}
	if (!ft_strcmp(split_copy[0], "WE") && !game->assets.west)
	{
		if (!check_valid_path(split_copy, \
			split_copy[1], &game->assets.west))
			return (FALSE);
	}
	return (TRUE);
}
