/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:55 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:58:56 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	*get_texture_index(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x < 0)
			return (&game->textures.w_wall);
		else
			return (&game->textures.e_wall);
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
			return (&game->textures.s_wall);
		else
			return (&game->textures.n_wall);
	}
	return (NULL);
}

void	set_color_to_pixel(t_game *game, int x, int y, int color)
{
	int	*pixels;
	int	pixel;

	pixels = (int *)game->img.addr;
	pixel = y * (game->img.line_len / 4) + x;
	pixels[pixel] = color;
}

void	set_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			set_color_to_pixel(game, x, y, game->assets.ceiling_color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT - 1)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			set_color_to_pixel(game, x, y, game->assets.floor_color);
			x++;
		}
		y++;
	}
}

void	get_img_ready(t_game *game, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		color;
	t_img	*curr;

	if ((game->ray.side == 0 && game->ray.ray_dir_x < 0)
		|| (game->ray.side == 1 && game->ray.ray_dir_y > 0))
		game->ray.tex_x = TEX_SIZE - game->ray.tex_x - 1;
	step = 1.0 * TEX_SIZE / game->ray.line_height;
	tex_pos = (game->ray.draw_start - WINDOW_HEIGHT / \
		2 + game->ray.line_height / 2) * step;
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		game->ray.tex_y = (int)tex_pos & (TEX_SIZE - 1);
		tex_pos += step;
		curr = get_texture_index(game);
		color = ((int *)curr->addr)[game->ray.tex_y * \
			(curr->line_len / 4) + game->ray.tex_x];
		if (!game->ray.side)
			color = (color >> 1) & 8355711;
		set_color_to_pixel(game, x, y, color);
		y++;
	}
}

void	init_value_to_draw(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.perp_wall_dist = game->ray.side_dist_x - \
			game->ray.delta_dist_x;
		game->ray.wall_x = game->ray.pos_y + \
			game->ray.perp_wall_dist * game->ray.ray_dir_y;
	}
	else
	{
		game->ray.perp_wall_dist = game->ray.side_dist_y \
			- game->ray.delta_dist_y;
		game->ray.wall_x = game->ray.pos_x + \
			game->ray.perp_wall_dist * game->ray.ray_dir_x;
	}
	game->ray.wall_x -= floor(game->ray.wall_x);
	game->ray.line_height = (int)(WINDOW_HEIGHT / game->ray.perp_wall_dist);
	game->ray.draw_start = -(game->ray.line_height) / 2 + WINDOW_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if (game->ray.draw_end >= WINDOW_HEIGHT)
		game->ray.draw_end = WINDOW_HEIGHT - 1;
	game->ray.tex_x = (int)(game->ray.wall_x * (double)TEX_SIZE);
}
