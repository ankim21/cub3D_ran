/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:39:28 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:39:31 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//lib
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "error_msg.h"
# include "map_attributes.h"
# include "structures.h"
# include "../libft/libft.h"

//define
# define BUFFER_SIZE 1
# define TRUE 1
# define FALSE 0
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480
# define BLOCK_SIZE 10
# define TEX_SIZE 64
# define MOVESPEED 0.1
# define ROTSPEED 0.3

//move.c
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//get_next_line.c
char	*get_next_line(int fd);

//init_dda.c
void	init_dir(t_game *game);
void	init_plane(t_game *game);
void	init_dda(t_game *game);
void	init_raycasting(t_game *game, int x);

//free_game.c
int		clean_exit(t_game *game);
void	dump(char **str, int words);
void	free_2d_array(char **arr);

//launch_mlx
int		launch_mlx(t_game *game);
void	create_mini_map(t_game *game);

//raycasting.c
void	create_pixel_block(t_img *img, int x, int y, int color);
void	start_rendering(t_game *game);

//render.c
int		get_int_color(int r, int g, int b);
int		get_textures(t_game *game);
void	init_value_to_draw(t_game *game);
void	get_img_ready(t_game *game, int x);
void	set_color_to_pixel(t_game *game, int x, int y, int color);
void	set_floor_and_ceiling(t_game *game);

//rotations.c
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

//utils.c
void	print_error(char *s);
void	open_fd(char *s, t_game *game);
char	*get_right_copy(t_game *game, int index, int start_map_cpy);
void	print_error(char *s);

//utils_spaces.c
int		is_only_space(char *str);
void	replace_spaces(t_game *game, char **map_cpy);

//validity_args.c
int		check_validity_args(int ac, char *av);

//validity_file.c
int		check_validity_file(char *av, t_game *game);
bool	is_valid_player_char(char c);

//validity_file_infos.c
bool	check_textures_and_colors(t_game *game);
bool	all_infos(t_game *game);

//validity_file_infos_colors.c
bool	on_color_line(char *s);
bool	check_color_line(char **split_copy, t_game *game);

//validity_file_infos_textures.c
bool	on_texture_line(char *s);
bool	check_textures_line(char **split_copy, t_game *game);

//validity_of_file_map.c
bool	check_map_content(t_game *game);

//validity_map_infos.c
char	**get_map_copy(t_game *game);
bool	check_for_target(t_point *start, char **map, int max_width);
bool	flood_fill_algorithm(char **map, t_point size, int x, int y);
bool	check_top_and_bottom(char *top, char *bottom);

#endif