/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:59 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:59:00 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//we rotate cam direction + cam plane
//vectors rotate withe ortatin matrix
// [ cos(a) -sin(a) ]
// [ sin(a)  cos(a) ]

void	rotate_right(t_game *game)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = game->ray.dir_x;
	game->ray.dir_x = game->ray.dir_x * cos(ROTSPEED) - \
		game->ray.dir_y * sin(ROTSPEED);
	game->ray.dir_y = old_dir_x * sin(ROTSPEED) + \
		game->ray.dir_y * cos(ROTSPEED);
	old_plane_x = game->ray.plane_x;
	game->ray.plane_x = game->ray.plane_x * \
		cos(ROTSPEED) - game->ray.plane_y * sin(ROTSPEED);
	game->ray.plane_y = old_plane_x * sin(ROTSPEED) + \
		game->ray.plane_y * cos(ROTSPEED);
}

void	rotate_left(t_game *game)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = game->ray.dir_x;
	game->ray.dir_x = game->ray.dir_x * \
		cos(-ROTSPEED) - game->ray.dir_y * sin(-ROTSPEED);
	game->ray.dir_y = old_dir_x * sin(-ROTSPEED) + \
		game->ray.dir_y * cos(-ROTSPEED);
	old_plane_x = game->ray.plane_x;
	game->ray.plane_x = game->ray.plane_x * \
		cos(-ROTSPEED) - game->ray.plane_y * sin(-ROTSPEED);
	game->ray.plane_y = old_plane_x * \
		sin(-ROTSPEED) + game->ray.plane_y * cos(-ROTSPEED);
}
