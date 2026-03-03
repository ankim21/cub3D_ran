/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:37 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 13:20:16 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_pixel_block(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;
	int		j;

	j = 0;
	while (j < BLOCK_SIZE)
	{
		i = 0;
		while (i < BLOCK_SIZE)
		{
			pixel = img->addr + ((y + j) * img->line_len) + \
				((x + i) * (img->bits_per_pixel / 8));
			*(unsigned int *)pixel = color;
			i++;
		}
		j++;
	}
}

void	create_mini_map(t_game *game)
{
	int		i;
	int		j;
	char	elem;

	i = 0;
	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			elem = game->map.array[i][j];
			if (elem == '1')
				create_pixel_block(&game->img, j * \
					BLOCK_SIZE, i * BLOCK_SIZE, 0x000000FF);
			else if (elem == '0')
				create_pixel_block(&game->img, j * \
					BLOCK_SIZE, i * BLOCK_SIZE, 0x00FFFFFF);
			else if (elem == 'W' || elem == 'E' || elem == 'S' || elem == 'N')
				create_pixel_block(&game->img, j * \
					BLOCK_SIZE, i * BLOCK_SIZE, 0x0000FF00);
			j++;
		}
		i++;
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == MOVE_LEFT)
		move_left(game);
	else if (keycode == MOVE_RIGHT)
		move_right(game);
	else if (keycode == MOVE_UP)
		move_forward(game);
	else if (keycode == MOVE_DOWN)
		move_backward(game);
	else if (keycode == ROT_LEFT)
		rotate_left(game);
	else if (keycode == ROT_RIGHT)
		rotate_right(game);
	else if (keycode == ESC)
		clean_exit(game);
	return (0);
}

int	launch_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_error(MLX_INIT);
		clean_exit(game);
	}
	game->mlx_win = \
		mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "The window");
	game->img.mlx_img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img,
			&game->img.bits_per_pixel, &game->img.line_len, &game->img.endian);
	if (!game->mlx_win)
		return (print_error(MLX_WIN), clean_exit(game), 1);
	if (!get_textures(game))
		clean_exit(game);
	start_rendering(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 17, 1L << 15, clean_exit, game);
	mlx_loop(game->mlx);
	return (0);
}
