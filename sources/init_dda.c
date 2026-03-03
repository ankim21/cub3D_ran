/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:32 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:58:34 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_dir(t_game *game)
{
	char	or;

	or = game->player.orientation;
	if (or == 'N')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = -1;
	}
	else if (or == 'S')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = 1;
	}
	else if (or == 'E')
	{
		game->ray.dir_x = 1;
		game->ray.dir_y = 0;
	}
	else
	{
		game->ray.dir_x = -1;
		game->ray.dir_y = 0;
	}
}

void	init_plane(t_game *game)
{
	char	or;

	or = game->player.orientation;
	if (or == 'N')
	{
		game->ray.plane_x = 0.66;
		game->ray.plane_y = 0;
	}
	else if (or == 'S')
	{
		game->ray.plane_x = -0.66;
		game->ray.plane_y = 0;
	}
	else if (or == 'E')
	{
		game->ray.plane_x = 0;
		game->ray.plane_y = 0.66;
	}
	else
	{
		game->ray.plane_x = 0;
		game->ray.plane_y = -0.66;
	}
}

void	init_dda(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->ray.pos_x - \
			game->ray.map_x) * game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - \
			game->ray.pos_x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->ray.pos_y - \
			game->ray.map_y) * game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + \
			1.0 - game->ray.pos_y) * game->ray.delta_dist_y;
	}
}

void	init_raycasting(t_game *game, int x)
{
	game->ray.cam_x = 2 * x / (double)WINDOW_WIDTH - 1;
	game->ray.ray_dir_x = game->ray.dir_x + \
		game->ray.plane_x * game->ray.cam_x;
	game->ray.ray_dir_y = game->ray.dir_y + \
		game->ray.plane_y * game->ray.cam_x;
	game->ray.map_x = (int)game->ray.pos_x;
	game->ray.map_y = (int)game->ray.pos_y;
	if (game->ray.ray_dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	if (game->ray.ray_dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
}
